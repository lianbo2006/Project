from django import forms
from django.core.exceptions import ValidationError

def comment_validator(comment):
    keywords = ["发票", "钱"]
    # 如果你用 python2 得这么写
    # keywords = [u"发票", u"钱"]
    for keyword in keywords:
        if keyword in comment:
            raise ValidationError("Your comment contains invalid words,please check it again.")

def words_validator(comment):
    if len(comment) < 4:
        raise ValidationError('Not enough words')


class CommentForm(forms.Form):
    name = forms.CharField(max_length=50)
    content = forms.CharField(
        widget=forms.Textarea(),
        error_messages={
            'requied':'please write something'
            },
        validators=[words_validator ,comment_validator]
        )
