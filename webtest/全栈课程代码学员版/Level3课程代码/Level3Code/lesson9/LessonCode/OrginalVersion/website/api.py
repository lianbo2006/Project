from website.models import Video
from rest_framework import serializers
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status


class VideoSerializer(serializers.ModelSerializer):

    class Meta:
        model = Video
        fields = '__all__'


@api_view(['GET'])
def video(request):
    if request.method == 'GET':
        video_list = Video.objects.all()
        serializer = VideoSerializer(video_list, many=True)
        return Response(serializer.data)
    # if request.method == 'POST':
    #     serializer
