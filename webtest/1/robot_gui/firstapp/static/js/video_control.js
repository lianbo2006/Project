
// var video_raw=document.getElementById("cam_raw");
// var src_site1="http://localhost:8888/stream?topic=/camera/rgb/image_raw";
// var src_site２="http://localhost:8888/stream?topic=/camera/depth/image_raw";
// var src_site３="{% static 'images/blackback.jpg' %}";
// var vidShow='停止';

function playPause()
{
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
