from django.shortcuts import render, Http404, redirect, HttpResponse
from website.models import Video, Ticket
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.contrib.auth import authenticate, login
from website.form import LoginForm
from django.contrib.auth.decorators import login_required
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.core.exceptions import ObjectDoesNotExist

# 插入开始
# /m/userlistpanel/login/  登录页面
# /m/userlistpanel/  所有用户页面
# /m/userdetail/  用户详情页面

def userlogin(request):
    if request.method=='GET':
        return render(request, 'userListPanelLogin.html')
    elif request.method=='POST':
        context = {}
        form = AuthenticationForm(data=request.POST)
        if form.is_valid():
            login(request, form.get_user())
            return redirect(to="usrelist")
        else:
            errormessage="Login Error"
            context['errormessage']=errormessage
        return render(request, 'userListPanelLogin.html',context=context)


def usrelist(request):
    return render(request, 'userListPanel.html')




def userdetail(request):
    return render(request, 'userDetail.html')



# 插入结束
