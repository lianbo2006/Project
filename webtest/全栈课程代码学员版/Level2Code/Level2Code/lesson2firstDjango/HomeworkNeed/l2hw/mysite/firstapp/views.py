from django.shortcuts import render,redirect
from firstapp.models import Article,Comment
from firstapp.forms import CommentForm

# Create your views here.
def index(request):

    article_list=Article.objects.all()
    context={}
    context['article_list']=article_list
    return render(request,'list0.html',context)

def detail(request, id):
    article = Article.objects.get(id=id)

    if request.method == "GET":
        form = CommentForm

    context = {}
    context["article"] = article
    context['form'] = form

    return render(request, 'detail.html', context)

def comment(request, id):
    if request.method == "POST":
        form = CommentForm(request.POST)
        if form.is_valid():
            name = form.cleaned_data["name"]
            comment = form.cleaned_data["comment"]
            article = Article.objects.get(id=id)
            c = Comment(name=name, comment=comment, belong_to=article)
            c.save()
            return redirect(to="detail", id=id)
    return redirect(to="detail", id=id)
