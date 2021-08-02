__author__ = 'a2'

def init():
    cola=[]
    return cola
def add(cola,num):
    cola.append(num)

def es_vacia(cola):
    n=len(cola)
    return n==0
def remove(cola):
    if es_vacia(cola)==False:
        x=cola[0]
        del cola[0]