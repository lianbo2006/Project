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
    name = models.CharField(max_length=10)
    avatar = models.CharField(max_length=100, default="static/images/default.png")
    content = models.TextField(null=True, blank=True)
    createtime = models.DateField(auto_now=True)
    create_time = models.TimeField(auto_now=True)
    def __str__(self):
        return self.content
