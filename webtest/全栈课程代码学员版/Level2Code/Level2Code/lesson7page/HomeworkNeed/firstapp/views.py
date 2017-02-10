from django.shortcuts import render
from firstapp.models import Article

# Create your views here.

def index(request):
    article_list = Article.objects.all()

    context = {}
    context["article_list"] = article_list

    return render(request, 'index.html', context)