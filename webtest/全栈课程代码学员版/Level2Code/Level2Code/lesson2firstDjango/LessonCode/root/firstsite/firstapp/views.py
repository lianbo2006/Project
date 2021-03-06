from django.shortcuts import render, HttpResponse
from firstapp.models import People, Article
# from django.template import Context, Template

# Create your views here.
def first_try(request):
    person = People(name='Spock', job='officer')
    html_string = '''
        <html>
            <head>
                <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/semantic-ui/2.2.4/semantic.css" media="screen" title="no title" charset="utf-8">
            </head>
            <body>
            <h1 class="ui center aligned icon header">
                <i class="hand spock icon"></i>
                Hello, {{ person.name }}
            </h1>
            </body>
        </html>
    '''
    t = Template(html_string)
    c = Context({'person': person})
    web_page = t.render(c)
    return HttpResponse(web_page)

def index(request):
    print(request)
    print('==='*30)
    print(dir(request))
    print('==='*30)
    print(type(request))
    print('==='*30)
    queryset=request.GET.get('tag')
    if queryset:
        article_list = Article.objects.filter(tag=queryset)
    else:
        article_list = Article.objects.all()
    print(queryset)
    context = {}
    context['article_list'] = article_list
    index_page = render(request, 'first_web_2.html', context)
    return index_page
