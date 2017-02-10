from django import forms
from django.core.exceptions import ValidationError

def comment_validator(comment):
    ban_words = ["发票", "钱","fuck",]
    for ban_word in ban_words:
        if ban_word in comment:
            raise ValidationError('评论中有非法词语，请检查后提交')

def words_validator(comment):
    if len(comment) < 4:
        raise ValidationError('评论不可少于４个字符')


class CommentForm(forms.Form):
    name = forms.CharField(max_length=50)
    comment = forms.CharField(
        widget=forms.Textarea(),
        error_messages={
            'required':'评论不能为空'
            },
        validators=[words_validator, comment_validator]
        )
