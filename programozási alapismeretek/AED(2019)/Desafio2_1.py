__author__ = 'a4'
'''Su tarea es desarrollar un programa que permita cargar por teclado el valor de n,
y luego calcule y muestre todos los valores de la órbita de n, mostrando también
(al final) el valor de la longitud de la órbita de n, el promedio entre todos los
valores de esa órbita, y el valor que haya sido el mayor de todos en la órbita.'''

def par(n):
    b = n / 2
    return b

def impar(n):
    c = 3 * n + 1
    return c

def suma(h):
    a = 0
    for i in h:
        a += i
    return a

def promedio(sumatoria, cantDigitos):
    r = sumatoria / cantDigitos
    return r

def principal():
    n = int(input('Ingrese un numero entero positivo:'))
    orbita = [n]
    a = 0
    may = n
    while n != 1:
        if n % 2 == 0:
            a = par(n)
            orbita.append(a)
        else:
            a = impar(n)
            orbita.append(a)
        if a > may:
            may = a
        n = a
    item2 = len(orbita)
    sumatoria = suma(orbita)
    item3 = promedio(sumatoria, item2)
    print('Orbita de n:', orbita)
    print('Longitud de la orbita:', item2)
    print('Promedio de todos los valores de la orbita', item3)
    print('Mayor de los numeros en esa orbita', may)



principal()
