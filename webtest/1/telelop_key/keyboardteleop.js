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
var t;
var c=0;
count=0;

// 定义线速度x与角速度y
var vx=0;
var vz=0;

// 设定速度增量
var vx_click_increment = 0.05;
var vz_click_increment = 0.1;

//　定义新的JSON结构速度消息
var cmdVel1 = new ROSLIB.Topic({
  ros : ros,
  name : '/mobile_base/commands/velocity',
  messageType : 'geometry_msgs/Twist'
});

//　定义消息发布函数
function cmdPub(){
  var twist = new ROSLIB.Message({
    angular : {
      x : 0,
      y : count++,
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
		vz += vz_click_increment;
	}
	// 向前
	else if (code == 'forward' ) {
		vx += vx_click_increment;
	}
	// 向右
	else if (code == 'right') {
		vz -= vz_click_increment;
	}
	// 向后
	else if (code == 'backward') {
		vx -= vx_click_increment;
	}
  //　向左前
  else if (code == 'strafe_left') {
		vx += vx_click_increment;
    vz += vz_click_increment;
	}
  //　向右前
  else if (code == 'strafe_right') {
		vx += vx_click_increment;
    vz -= vz_click_increment;
	}
  cmdPub();
}

//　定义停止函数
function stopRobot() {
  vx = vz = 0;
  cmdPub ();
}

// 定义计时器启动函数
function startTimer(code1) {
  setSpeed(code1);
  t=setInterval(function(){setSpeed(code1)},1000);
};

// 定义计时器停止函数
function stopTimer(){
  clearInterval(t);
  stopRobot();
}
