from django import forms
from django.core.exceptions import ValidationError

def word_validator(comment):
    if len(comment) < 4:
        raise ValidationError("评论不能少于四个字符")

def comment_validator(comment):
    keywords = ["发票", "钱","fuck"]
    for keyword in keywords:
        if keyword in comment:
            raise ValidationError("评论含有非法字符请检查后重新提交")

class CommentForm(forms.Form):
    name = forms.CharField(max_length=50)
    comment = forms.CharField(
        widget=forms.Textarea(),
        error_messages = {
            "required": '评论不能为空'
            },
        validators = [word_validator, comment_validator]
        )
