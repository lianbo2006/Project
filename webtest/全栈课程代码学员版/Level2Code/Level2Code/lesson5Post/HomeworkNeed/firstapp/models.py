from django.db import models

# Create your models here.

class Article(models.Model):
    title = models.CharField(max_length=500)
    img = models.CharField(max_length=250)
    content = models.TextField(null=True, blank=True)
    views = models.IntegerField(default=0)
    likes = models.IntegerField(default=0)
    createtime = models.DateField()

    def __str__(self):
        return self.title

class Comment(models.Model):
    name = models.CharField(null=True, blank=True, max_length=50)
    avater= models.CharField(null=True, blank=True, max_length=500,default="static/images/default.png")
    content = models.TextField(null=True)
    creatdate= models.DateField(auto_now=True)
    creattime= models.TimeField(auto_now=True)


    def __str__(self):
        return self.content
