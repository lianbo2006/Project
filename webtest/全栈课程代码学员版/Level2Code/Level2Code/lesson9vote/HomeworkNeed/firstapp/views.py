from django.shortcuts import render
from firstapp.models import Article

# Create your views here.

def index(request):
    article_list = Article.objects.all()

    context = {}
    context["article_list"] = article_list

    return render(request, 'index.html', context)

def detail(request, id):
    article = Article.objects.get(id=id)

    if request.method == "get":
        form = CommentForm 

    context = {}
    context["article"] = article
    context['form'] = form
    
    return render(request, 'detail.html', context)

def comment(request, id):
    if request.method == "post":
        form = CommentForm(request.POST)
        if form.is_valid():
            name = form.cleaned_data["name"]
            comment = form.cleaned_data["comment"]
            article = Article.objects.get(id=id)
            c = Comment(name=name, comment=comment, belong_to=article)
            c.save()
            return redirect(to="detail", id=id)
    return redirect(to="detail", id=id)