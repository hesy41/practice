from django.urls import path

from . import views

# url config that map view.py to a url so that we could call it
urlpatterns = [
    path('', views.index, name='index'),
]