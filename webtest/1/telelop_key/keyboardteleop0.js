/**
 * @author Russell Toris - rctoris@wpi.edu
 */

var KEYBOARDTELEOP = KEYBOARDTELEOP || {
  REVISION : '0.4.0-SNAPSHOT'
};

/**
 * @author Russell Toris - rctoris@wpi.edu
 */

/**
 * Manages connection to the server and all interactions with ROS.
 *
 * Emits the following events:
 *   * 'change' - emitted with a change in speed occurs
 *
 * @constructor
 * @param options - possible keys include:
 *   * ros - the ROSLIB.Ros connection handle
 *   * topic (optional) - the Twist topic to publish to, like '/cmd_vel'
 *   * throttle (optional) - a constant throttle for the speed
 */
KEYBOARDTELEOP.Teleop = function(options) {
  var that = this;
  options = options || {};
  var ros = options.ros;
  var topic = options.topic || '/cmd_vel';
  // permanent throttle
  var throttle = options.throttle || 1.0;

  // used to externally throttle the speed (e.g., from a slider)
  this.scale = 1.0;

  // linear x and y movement and angular z movement
  var x = 0;
  var y = 0;
  var z = 0;

  var cmdVel = new ROSLIB.Topic({
    ros : ros,
    name : topic,
    messageType : 'geometry_msgs/Twist'
  });

  // sets up a key listener on the page used for keyboard teleoperation
  var handleKey = function(keyCode, keyDown) {
    // used to check for changes in speed
    var oldX = x;
    var oldY = y;
    var oldZ = z;

    var pub = true;

    var speed = 0;
    // throttle the speed by the slider and throttle constant
    if (keyDown === true) {
      speed = throttle * that.scale;
    }
    // check which key was pressed
    switch (keyCode) {
      case 65:
        // turn left
        z = 1 * speed;
        break;
      case 87:
        // up
        x = 0.5 * speed;
        break;
      case 68:
        // turn right
        z = -1 * speed;
        break;
      case 83:
        // down
        x = -0.5 * speed;
        break;
      case 69:
        // strafe right
        x = 0.5 * speed;
        z = -1 * speed;
        break;
      case 81:
        // strafe left
        x = 0.5 * speed;
        z = 1 * speed;
        break;
      case 88:
        // stop
        stopRobot();
        break;
      // default:
      //   pub = false;
    }

    // publish the command
    if (pub === true) {
      var twist = new ROSLIB.Message({
        angular : {
          x : 0,
          y : 0,
          z : z
        },
        linear : {
          x : x,
          y : 0,
          z : 0,
        }
      });
      cmdVel.publish(twist);

      // check for changes
      if (oldX !== x || oldY !== y || oldZ !== z) {
        that.emit('change', twist);
      }
    }
  };

  // handle the key
  var body = document.getElementsByTagName('body')[0];
  body.addEventListener('keydown', function(e) {
    handleKey(e.keyCode, true);
  }, false);
  body.addEventListener('keyup', function(e) {
    handleKey(e.keyCode, false);
  }, false);
};
KEYBOARDTELEOP.Teleop.prototype.__proto__ = EventEmitter2.prototype;

var ros = new ROSLIB.Ros({
  url : 'ws://localhost:9090'
});

ros.on('connection', function() {
  console.log('Connected to websocket server.');
});

ros.on('error', function(error) {
  console.log('Error connecting to websocket server: ', error);
});

ros.on('close', function() {
  console.log('Connection to websocket server closed.');
});

// linear x movement and angular z movement
var vx=0;
var vz=0;
// How much to increment speeds with each key press
var vx_click_increment = 0.05;
var vz_click_increment = 0.1;

var cmdVel1 = new ROSLIB.Topic({
  ros : ros,
  name : '/mobile_base/commands/velocity',
  messageType : 'geometry_msgs/Twist'
});


function setSpeed(code) {

	// Left arrow
	if (code == 'left' ) {
		vz += vz_click_increment;
	}
	// Up arrow
	else if (code == 'forward' ) {
		vx += vx_click_increment;
	}
	// Right arrow
	else if (code == 'right') {
		vz -= vz_click_increment;
	}
	// Down arrow
	else if (code == 'backward') {
		vx -= vx_click_increment;
	}
  // strafe_left
  else if (code == 'strafe_left') {
		vx += vx_click_increment;
    vz += vz_click_increment;
	}
  //strafe_right
  else if (code == 'strafe_right') {
		vx += vx_click_increment;
    vz -= vz_click_increment;
	}

  var twist = new ROSLIB.Message({
    angular : {
      x : 0,
      y : 0,
      z : vz,
    },
    linear : {
      x : vx,
      y : 0,
      z : 0,
    }
  });
  cmdVel1.publish(twist);

}

function stopRobot() {
  vx = vz = 0;
  var twist0 = new ROSLIB.Message({
    angular : {
      x : 0,
      y : 0,
      z : 0,
    },
    linear : {
      x : 0,
      y : 0,
      z : 0,
    }
  });
  cmdVel1.publish(twist0);
}
