from website.models import Video
from rest_framework import serializers
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status

from rest_framework.decorators import api_view, authentication_classes
from rest_framework.authentication import TokenAuthentication


class VideoSerializer(serializers.ModelSerializer):
    title = serializers.CharField(min_length=1)

    class Meta:
        model = Video
        fields = '__all__'
        depth = 1


@api_view(['GET', 'POST'])
@authentication_classes((TokenAuthentication,))
def video(request):
    print(request.user)
    print(request.auth)
    video_list = Video.objects.order_by('-id')
    if request.method == 'GET':
        if request.auth:
            serializer = VideoSerializer(video_list, many=True)
            return Response(serializer.data)
        else:
            serializer = VideoSerializer(video_list[:5], many=True)
            return Response(serializer.data)

    elif request.method == 'POST':
        serializer = VideoSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        body = {
            'body': serializer.errors,
            'msg': '40001'
        }
        return Response(body, status=status.HTTP_400_BAD_REQUEST)


@api_view(['PUT', 'DELETE'])
@authentication_classes((TokenAuthentication,))
def video_card(request, id):
    video_card = Video.objects.get(id=id)
    USER_CAN = {
        "DELETE": request.user.profile == video_card.owner or (
                    request.user == 'admin')
    }
    if request.method == 'PUT':
        serializer = VideoSerializer(video_card, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
    elif request.method == 'DELETE':
        if USER_CAN["DELETE"]:
            video_card.delete()
            return Response({'msg': 'A-OK'}, status=status.HTTP_201_CREATED)
        else:
            return Response({'msg': 'You cant touch this'}, status=status.HTTP_403_FORBIDDEN)
