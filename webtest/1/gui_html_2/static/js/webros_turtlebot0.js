// 设定相关端口信息
var rosbridgePort = "9090";
var videoPort = "8080";

// 分别定义服务的主机变量
var rosbridgeHost  = "123.206.22.180";
var videoHost  = "123.206.22.180";

// 设定rosbridge_server信息
var rbServer = new ROSLIB.Ros({
    url : 'ws://' + rosbridgeHost + ':' + rosbridgePort
 });

 // 设置web_video_server相关参数
 var src_site1 = "http://" + videoHost + ":" + videoPort + "/stream?topic=/usb_cam/image_raw&quality=60&width=240&height=180";
 var src_site2 = "http://" + videoHost + ":" + videoPort + "/stream?topic=/camera/depth/image_raw";
 var src_site3="static/images/blackback.jpg";
 var vidShow='停止';

 // 定义初始化函数
 function init() {
   // 修改相关端口信息
   rosbridgePort = document.getElementById('rosbridgePort').value;
   videoPort = document.getElementById('videoPort').value;

   // 修改服务的主机变量
   rosbridgeHost  = document.getElementById('rosbridgeHost').value;
   videoHost  = document.getElementById('videoHost').value;

   // 修改rosbridge_server信息
  rbServer = new ROSLIB.Ros({
       url : 'ws://' + rosbridgeHost + ':' + rosbridgePort
    });

   // 连接rosbridge_server并返回信息进行显示
   rbServer.on('connection', function() {
       alert("websocket 服务器已连接");
       console.log('Connected to websocket server.');
   });
    rbServer.on('error', function(error) {
        alert("连接 websocket 服务器错误");
        console.log('Error connecting to websocket server: ', error);
    });
    rbServer.on('close', function() {
        alert("websocket 服务器已关闭");
        console.log('Connection to websocket server closed.');
     });

     // 修改web_video_server相关参数
     src_site1 = "http://" + videoHost + ":" + videoPort + "/stream?topic=/usb_cam/image_raw&quality=50&width=200&height=160";
     src_site2 = "http://" + videoHost + ":" + videoPort + "/stream?topic=/camera/depth/image_raw";
     var video_raw = document.getElementById("cam_raw");
     video_raw.src=src_site3;
}

// 创建rostopic,设定主节点，消息名和消息类型
var cmdVelTopic = new ROSLIB.Topic({
    ros : rbServer,
    name : '/cmd_vel_mux/input/teleop',
    messageType : 'geometry_msgs/Twist'
});

// 定义视频显示函数
function playPause(){
  var video_raw = document.getElementById("cam_raw");
  if (vidShow=='停止'){
    vidShow='彩色';
    video_raw.src = src_site1;
  }
  else {
    vidShow='停止';
    video_raw.src = src_site3;

  }
  // else if (vidShow=='彩色') {
  //   vidShow='深度';
  //   video_raw.src=src_site2;
  // }
  //
  // else{
  //   vidShow='停止';
  //   video_raw.src=src_site3;
  // }
}

//　计时器定义
var t1;
var t2;
var c = 0;

// // 测试用变量
// var count=0;

// 定义线速度x与角速度y以及它们的阈值
var vx = 0;
var vz = 0;
var vxmax = 0.2;
var vzmax = 0.5;

// 设定速度增量
var vx_increment = 0.02;
var vz_increment = 0.1;


//　定义消息发布函数
function cmdPub(){
  vx = Math.min(Math.abs(vx), vxmax) * Math.sign(vx);
  vz = Math.min(Math.abs(vz), vzmax) * Math.sign(vz);

  var twist = new ROSLIB.Message({
    linear : {
      x : vx,
      y : 0,
      z : 0,
    },
    angular : {
      x : 0,
      y : 0,
      z : vz,
    }
  });
  cmdVelTopic.publish(twist);
}

//　定义速度设定函数，通过code判断按键
function setSpeed(code) {
  var vxText = 0 + Number(document.getElementById('vxText').value);
  var vzText = 0 + Number(document.getElementById('vzText').value);
  var vxDis = Math.abs(vxText - vx);
  var vzDis = Math.abs(vzText - vz);

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
    if (vxDis > vx_increment && vzDis > vz_increment) {
      vx=(Math.abs(vx) + vx_increment)* Math.sign(vxText);
      vz=(Math.abs(vz) + vz_increment)* Math.sign(vzText);
    }
    else if (Math.abs(vxDis) > vx_increment && Math.abs(vzDis) <= vz_increment) {
      vx=(Math.abs(vx) + vx_increment)* Math.sign(vxText);
      vz = vzText;
    }
    else if (Math.abs(vzDis) > vz_increment && Math.abs(vxDis) <= vx_increment) {
      vz=(Math.abs(vz) + vz_increment)* Math.sign(vzText);
      vx = vzText;
    }
    else if (Math.abs(vzDis) <= vz_increment && Math.abs(vxDis) <= vx_increment) {
      vx = vxText;
      vz = vzText;
    }
	}
  cmdPub();
}

// 定义最大值设置函数
function setMax() {
  vxmax = Math.min(Math.abs(document.getElementById('vxMaxText').value), 0.5);
  vzmax = Math.min(Math.abs(document.getElementById('vzMaxText').value), 1.0);
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

// 定义计时器停止函数
function stopTimer() {
  clearInterval(t1);
  if (vx == 0 && vz == 0) {
    clearInterval(t2);
  }
  else if (vx != 0 || vz != 0) {
    t2 = setInterval("stopRobot()", 50);
  }
  else {
    instantStopRobot();
  }
}
