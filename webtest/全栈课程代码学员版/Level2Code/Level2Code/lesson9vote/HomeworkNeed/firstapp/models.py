from django.db import models

# Create your models here.
class Article(models.Model):
    title = models.CharField(max_length=500)
    img = models.CharField(max_length=250)
    content = models.TextField(null=True, blank=True)
    views = models.IntegerField()
    favs = models.IntegerField()
    createtime = models.DateField()
    
    def __str__(self):
        return self.title

class Comment(models.Model):
    name = models.CharField(max_length=500)
    avatar = models.CharField(max_length=250, default="static/images/default.png")
    content = models.TextField(null=True, blank=True)
    createtime = models.DateField(auto_now=True)

    belong_to = models.ForeignKey(to=Article, related_name="under_comments", null=True, blank=True)
    
    def __str__(self):
        return self.name
