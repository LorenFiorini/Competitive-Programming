__author__ = 'a2'

def init():
    pila=[]
    return pila

def es_vacia(pila):
    n=len(pila)
    return n == 0

def desapilar(pila):
    x=None
    if es_vacia(pila)==False:
        x=pila[-1]
        del pila[-1]
    return x
def apilar(pila,num):
    pila.append(num)

def test():
    p1 =init()
    apilar(p1,7)
    apilar(p1,3)
    apilar(p1,5)
    apilar(p1,2)
    print(p1)
    while es_vacia==False:
        x=desapilar(p1)
        print(x,end=" ")




test()