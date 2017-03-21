// 设定相关端口信息
var rosbridgePort = "9090";
var mjpegPort = "8888";

// 获得主机ip地址
thisHostName = "localhost";

// 分别定义服务的主机变量
var rosbridgeHost = thisHostName;
var mjpegHost = thisHostName;

// 设定rosbridge_server信息
var rbServer = new ROSLIB.Ros({
    url : 'ws://' + rosbridgeHost + ':' + rosbridgePort
 });

 // 连接rosbridge_server并返回信息进行显示
 function init() {
 rbServer.on('connection', function() {
     var fbDiv = document.getElementById('feedback');
     fbDiv.innerHTML += "<p>websocket 服务器已连接</p>";
     console.log('Connected to websocket server.');
 });
rbServer.on('error', function(error) {
    var fbDiv = document.getElementById('feedback');
    fbDiv.innerHTML += "<p>连接 websocket 服务器错误</p>";
    console.log('Error connecting to websocket server: ', error);
});
rbServer.on('close', function() {
    var fbDiv = document.getElementById('feedback');
    fbDiv.innerHTML += "<p>websocket 服务器已关闭</p>";
    console.log('Connection to websocket server closed.');
 });
 }

// These lines create a topic object as defined by roslibjs
var cmdVelTopic = new ROSLIB.Topic({
    ros : rbServer,
    name : '/cmd_vel_mux/input/teleop',
    messageType : 'geometry_msgs/Twist'
});

// // 设置web_video_server相关参数
// var video_raw = document.getElementById("cam_raw");
// var src_site1 = "http://" + mjpegHost + ":" + mjpegPort + "/stream?topic=/camera/rgb/image_raw";
// var src_site2 = "http://" + mjpegHost + ":" + mjpegPort + "/stream?topic=/camera/depth/image_raw";
// var src_site３="{% static 'images/blackback.jpg' %}";
// var vidShow='停止';

// 定义视频显示函数
function playPause(){
  if (vidShow=='停止'){
    vidShow='彩色';
    video_raw.src=src_site1;
  }
  else if (vidShow=='彩色') {
    vidShow='深度';
    video_raw.src=src_site２;
  }

  else{
    vidShow='停止';
    video_raw.src=src_site３;
  }
}

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
  cmdVelTopic.publish(twist);
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
  else if (code == 'set') {
		vx = 0 + Number(document.getElementById('vxText').value);
    vz = 0 + Number(document.getElementById('vzText').value);

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
};

// 定义计时器启动函数
function startTimer(code1) {
  setSpeed(code1);
  t1 = setInterval(function() {setSpeed(code1)}, 100);
}

function startTimer1(code2) {
  for (var i = 0; i < 20; i++) {
    t1 = setTimeout(function() {setSpeed(code2)}, 100);
  }
  // stopTimer();
}

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
