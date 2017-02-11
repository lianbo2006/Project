from django.db import models

# Create your models here.
class Article(models.Model):
    title = models.CharField(null=True, blank=True, max_length=500)
    content = models.TextField(null=True, blank=True)
    img= models.CharField(max_length=500)
    views=models.IntegerField(default=0)
    likes=models.IntegerField(default=0)
    createtime= models.DateField()
    editors_choice = models.BooleanField(default=False)

    def __str__(self):
        return self.title
class Comment(models.Model):
    name = models.CharField(max_length=500)
    avatar = models.CharField(max_length=250, default="static/images/default.png")
    comment = models.TextField(null=True, blank=True)
    createdate = models.DateField(auto_now=True)
    createtime = models.TimeField(auto_now=True)

    belong_to = models.ForeignKey(to=Article, related_name="under_comments", null=True, blank=True)

    def __str__(self):
        return self.comment
