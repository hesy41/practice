from django.db import models
import datetime
from django.utils import timezone
from django.contrib import admin

# Create your models here.
class Question(models.Model):
    question_text: str = models.CharField(max_length=200)
    pub_date: datetime = models.DateTimeField('date published')

    def __str__(self) -> str:
        return self.question_text

    @admin.display(
        boolean=True,
        ordering='pub_date',
        description='Published recently?',
    )
    def was_published_recently(self):
        now = timezone.now()
        return now - datetime.timedelta(days=1) <= self.pub_date <= now

class Choice(models.Model):
    #if a record in the parent table is deleted
    #then the corresponding records in the child table will automatically be deleted.
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.CharField(max_length=200)
    votes = models.IntegerField(default=0)

    def __str__(self) -> str:
        return self.choice_text
