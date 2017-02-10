from django.shortcuts import render, HttpResponse, redirect
from firstapp.models import Aritcle, Comment
from django.template import Context, Template
from firstapp.form import CommentForm

def index(request):
    print(request)
    print('==='*30)
    print(dir(request))
    print('==='*30)
    print(type(request))
    queryset = request.GET.get('tag')
    if queryset:
        article_list = Aritcle.objects.filter(tag=queryset)
    else:
        article_list = Aritcle.objects.all()
    context = {}
    context['article_list'] = article_list
    index_page = render(request, 'first_web_2.html', context)
    return index_page



def detail(request, page_num, error_form=None):
    context = {}
    form = CommentForm
    a = Aritcle.objects.get(id=page_num)
    best_comment = Comment.objects.filter(best_comment=True, belong_to=a)
    if best_comment:
        context['best_comment'] = best_comment[0]
    article = Aritcle.objects.get(id=page_num)
    context['article'] = article
    # context['comment_list'] = comment_list
    if error_form is not None:
        context['form'] = error_form
    else:
        context['form'] = form
    return render(request, 'article_detail.html', context)

def detail_comment(request, page_num):
    form = CommentForm(request.POST)
    if form.is_valid():
        name = form.cleaned_data['name']
        comment = form.cleaned_data['comment']
        a = Aritcle.objects.get(id=page_num)
        c = Comment(name=name, comment=comment, belong_to=a)
        c.save()
    else:
        return detail(request, page_num=page_num, error_form=form)

    return redirect(to='detail', page_num=page_num)
