from django.shortcuts import render


def video_list(request):
    return render(request, 'mobile_list.html', {})
