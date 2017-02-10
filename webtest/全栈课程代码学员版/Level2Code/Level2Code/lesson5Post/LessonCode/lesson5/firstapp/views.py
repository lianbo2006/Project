from django.shortcuts import render, HttpResponse, redirect
from firstapp.models import Article, Comment
from django.template import Context, Template
from firstapp.form import CommentForm

# Create your views here.


def index(request):
    queryset = request.GET.get('tag')
    if queryset:
        article_list = Article.objects.filter(tag=queryset)
    else:
        article_list = Article.objects.all()
    context = {}
    context['article_list'] = article_list
    index_page = render(request, 'first_web_2.html', context)
    return index_page

def detail(request):
    if request.method == 'GET':
        form = CommentForm
    if request.method == 'POST':
        form = CommentForm(request.POST)
        if form.is_valid():
            name = form.cleaned_data['name']
            comment = form.cleaned_data['comment']
            c = Comment(name=name, comment=comment)
            c.save()
            return redirect(to='detail')
    context = {}
    comment_list = Comment.objects.all()
    context['comment_list'] = comment_list
    context['form'] = form
    return render(request,'detail.html',context)
