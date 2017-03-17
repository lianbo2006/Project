from django.shortcuts import render

# Create your views here.
def video(request):
    context={}
    return render(request,'ros_web_video_server_test.html', context)
def robot_gui(request):
    context={}
    return render(request,'webros_turtlebot0.html', context)
