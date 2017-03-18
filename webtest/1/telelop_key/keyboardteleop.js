//　rosbridge键盘控制测试

//　与rosbridge_server建立连接
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

//　计时器定义
var t1;
var t2;
var c = 0;

// 测试用变量
// var count=0;

// 定义线速度x与角速度y以及它们的阈值
var vx = 0;
var vz = 0;
var vxmax = 0.5;
var vzmax = 1;

// 设定速度增量
var vx_increment = 0.02;
var vz_increment = 0.1;

//　定义新的JSON结构速度消息
var cmdVel1 = new ROSLIB.Topic({
  ros : ros,
  name : '/cmd_vel_mux/input/teleop',
  messageType : 'geometry_msgs/Twist'
});

//　定义消息发布函数
function cmdPub(){
  vx = Math.min(Math.abs(vx), vxmax) * Math.sign(vx);
  vz = Math.min(Math.abs(vz), vzmax) * Math.sign(vz);

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

//　定义速度设定函数，通过code判断按键
function setSpeed(code) {

	// 向左
	if (code == 'left' ) {
		vz += vz_increment;
	}
	// 向前
	else if (code == 'forward' ) {
		vx += vx_increment;
	}
	// 向右
	else if (code == 'right') {
		vz -= vz_increment;
	}
	// 向后
	else if (code == 'backward') {
		vx -= vx_increment;
	}
  //　向左前
  else if (code == 'strafe_left') {
		vx += vx_increment;
    vz += vz_increment;
	}
  //　向右前
  else if (code == 'strafe_right') {
		vx += vx_increment;
    vz -= vz_increment;
	}
  cmdPub();
}

//定义停止函数
function stopRobot() {
  if (vx == 0 && vz == 0) {
  clearInterval(t2);
  }
  else if (Math.abs(vx) > vx_increment && Math.abs(vz) > vz_increment) {
    vx=(Math.abs(vx) - vx_increment)* Math.sign(vx);
    vz=(Math.abs(vz) - vz_increment)* Math.sign(vz);
  }
  else if (Math.abs(vx) > vx_increment && Math.abs(vz) <= vz_increment) {
    vx=(Math.abs(vx) - vx_increment)* Math.sign(vx);
    vz = 0;
  }
  else if (Math.abs(vz) > vz_increment && Math.abs(vx) <= vx_increment) {
    vz=(Math.abs(vz) - vz_increment)* Math.sign(vz);
    vx = 0;
  }
  else if (Math.abs(vz) <= vz_increment && Math.abs(vx) <= vx_increment) {
    vx = vz = 0;
  }
  cmdPub ();
}


//　定义急停函数
function instantStopRobot() {
  vx = vz = 0;
  cmdPub ();
}

// 定义计时器启动函数
function startTimer(code1) {
  setSpeed(code1);
  t1 = setInterval(function() {setSpeed(code1)}, 100);
};

// 定义计时器停止函数
function stopTimer() {
  clearInterval(t1);
  if (vx == 0 && vz == 0) {
    clearInterval(t2);
  }
  else if (vx != 0 || vz != 0) {
    t2 = setInterval("stopRobot()", 25);
  }
  else {
    instantStopRobot();
  }
}
