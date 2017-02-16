from website.models import Video
from rest_framework import serializers
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status
from django.contrib.auth.models import User
from .models import UserProfile

from rest_framework.decorators import api_view, authentication_classes
from rest_framework.authentication import TokenAuthentication



class UserSerializer(serializers.ModelSerializer):
    # title = serializers.CharField(min_length=1)

    class Meta:
        model = User
        # fields = '__all__'
        fields=('id','username','email','profile')
        depth = 1
@api_view(['GET', 'POST'])
@authentication_classes((TokenAuthentication,))
def getuser(request):
    print(request.user.is_superuser)
    print(request.auth)
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    user_list = User.objects.filter(is_superuser=False)
    serializer = UserSerializer(user_list, many=True)
    return Response(serializer.data)

@api_view(['GET'])
@authentication_classes((TokenAuthentication,))
def oneuser(request, id):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    try:
        user = User.objects.get(id=id)
        serializer = UserSerializer(user)
        return Response(serializer.data,status=status.HTTP_200_OK)
    except:
        body = {"msg": "Fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)

@api_view(['PUT'])
@authentication_classes((TokenAuthentication,))
def banuser(request, id):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    try:
        user = User.objects.get(id=id)
        user.is_active = False
        user.save()
        body = {"msg": "Success"}
        return Response(body,status=status.HTTP_200_OK)
    except:
        body = {"msg": "Fail "}
        return Response(body,status=status.HTTP_403_FORBIDDEN)

@api_view(['POST'])
@authentication_classes((TokenAuthentication,))
def modifyinfo(request, id):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    try:
        user = User.objects.get(id=id)
        nickname = request.POST.get('nickname')
        password = request.POST.get('password')
        user.profile.nickname = nickname
        user.set_password(password)
        user.save()
        user.profile.save()
        body={"msg":"Success"}
        return Response(body,status=status.HTTP_200_OK)
    except:
        body = {"msg": "Fail"}
        return Response(body,status=status.HTTP_403_FORBIDDEN)

@api_view(['PUT'])
@authentication_classes((TokenAuthentication,))
def modifyauth(request, id):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    try:
        user = User.objects.get(id=id)
        user.profile.choices = "author"
        user.save()
        user.profile.save()
        body = {"msg": "Successful"}
        return Response(body, status=status.HTTP_200_OK)
    except:
        body = {"msg": "Fail"}
        return Response(status=status.HTTP_403_FORBIDDEN)

@api_view(['DELETE'])
@authentication_classes((TokenAuthentication,))
def delete(request, id):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    try:
        user = User.objects.get(id=id)
        user.delete()
        body = {"msg": "Successful"}
        return Response(body, status=status.HTTP_200_OK)
    except:
        body = {"msg": "Fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)

@api_view(['POST'])
@authentication_classes((TokenAuthentication,))
def createuser(request):
    if not request.user.is_superuser:
        body = {"msg": "Auth fail"}
        return Response(body, status=status.HTTP_403_FORBIDDEN)
    username = request.POST.get('username')
    password = request.POST.get('password')
    email = request.POST.get('email')
    choices = request.POST.get('choices')
    print(username,password,email,choices)
    if len(User.objects.filter(username=username))>0:
        return Response({'msg': 'username already exist'}, status=status.HTTP_403_FORBIDDEN)
    elif password=="":
        return Response({'msg': 'the password is invalid'}, status=status.HTTP_403_FORBIDDEN)
    else:
        newuser = User(username=username,email=email)
        newuser.set_password(password)
        newuser.save()
        profile = UserProfile(choices=choices,belong_to=newuser)
        profile.save()

        return Response({'msg':'create user success'},status=status.HTTP_201_CREATED)


# 以下是Video的序列化models
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
