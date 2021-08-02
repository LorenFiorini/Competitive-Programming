'''Mercado Libre es una aplicación muy conocida para permitir la compra/venta en línea de todo tipo de artículos en forma directa por cualquier usuario.
Se solicita simular los resultados de una búsqueda en Mercado Libre de un artículo x. Para ello, se requiere la realización de dos módulos independientes (registro y principal).

Cargar automáticamente los resultados de la búsqueda en un arreglo de n registros (n se ingresa por teclado). Por cada registro se debe indicar:

    código de publicación
    precio
    ubicación geográfica (1-23 identificando cada provincia de la Argentina)
    estado (nuevo/usado)
    cantidad disponible
    puntuación del vendedor ( 1-5 identificando 5 como Excelente y 1 Mala).

El arreglo debe quedar ordenado por código de publicación. Mostrar el vector generado.

Presentar un menú de opciones que permita realizar lo siguiente:

1)    Nuevos por precio: generar un nuevo arreglo conteniendo sólo las publicaciones de artículos nuevos. Mostrar el listado ordenado por precio (de menor a mayor).

2)    Usados por calificación: determinar cantidad de publicaciones en estado usado por cada puntuación de vendedor (5 totales).

3)    Distribución geográfica: informar la cantidad de artículos disponibles por ubicación geográfica y puntuación del vendedor, pero mostrando el resultado en forma de matriz o bien en forma de lista sólo para cantidades mayores a cero. Se debe mostrar el nombre de cada provincia (no el código) y la descripción de la puntuación del vendedor (no el código).

4)    Total provincial: a partir de la matriz, informar el total de artículos para una provincia que se ingresa por teclado (validar que se encuentre cargada).

5)    Precio promedio de usados: mostrar las publicaciones con estado usado, cuyo precio supera el precio promedio de usados del listado.

6)    Compra ideal: informar cual es el menor precio para un artículo nuevo, omitiendo los vendedores con calificación Mala.

7)    Comprar: buscar una publicación cuyo código se ingresa por teclado. Si no existe, informar con un mensaje. Si existe, preguntar al usuario qué cantidad de artículos desea comprar, validar que la cantidad disponible sea suficiente, y confirmar/rechazar la compra según corresponda.
def ordenamiento(vector)'''

import random
from Registro import *

def menu():
    tit ='{:^30}'.format('Mercado Libre')


    tit2 = '{:^30}'.format('MENU DE OPCIONES:')

    print(tit)
    print(tit2)

    print('1) Nuevos por precio')
    print('2) Usados por calificacion')
    print('3) Distribucion geografica')
    print('4) Total provincial')
    print('5) Precio promedio de usados')
    print('6) Compra ideal')
    print('7) Comprar')
    print('0) Salir')
    return validar_entre(0,7, "Ingrese una opcion: ")




def validar_mayor(minimo, mensaje):
    n = int(input(mensaje))
    while n < minimo:
        print('Error ingrese un valor mayor a', minimo)
        n = int(input(mensaje))
    return n


def validar_entre(minimo, maximo, mensaje):
    n = int(input(mensaje))
    while n < minimo or n > maximo:
        print('Error ingrese un valor entre {} y {}.\n'.format(minimo, maximo))
        n = int(input(mensaje))
    return n


def carga_automatica(vec):
    est = ('Nuevo', 'Usado')
    for i in range(len(vec)):
        codigo = random.randint(1000,100000)
        precio = round(random.uniform(1, 10000),2)
        prov = random.randint(1, 23)
        estado = random.choice(est)
        cant = random.randint(1, 1000)
        puntuacion = random.randint(0, 5)
        vec[i] = Articulo(codigo, precio, prov, estado, cant, puntuacion)

def ordenar(vec):
    for i in range(len(vec) - 1):
        for j in range(i + 1, len(vec)):
            if vec[i].codigo > vec[j].codigo:
                vec[i], vec[j] = vec[j], vec[i]

def mostrar(vec):
    for i in range(len(vec)):
        write(vec[i])
#-----------------------------------------------------------------------------------------------------------------------

def nuevos(vec):
    vec_nuevos = []
    for i in range(len(vec)):
        if vec[i].estado == 'Nuevo':
            vec_nuevos.append(vec[i])
    return vec_nuevos


def ordenar_precio(nvos):
    for i in range(len(nvos) - 1):
        for j in range(i + 1, len(nvos)):
            if nvos[i].precio > nvos[j].precio:
                nvos[i], nvos[j] = nvos[j], nvos[i]


def usado(vec):
    vec_usados = []
    for i in range(len(vec)):
        if vec[i].estado == 'Usado':
            vec_usados.append(vec[i])
    return vec_usados

def ordenar_por_calificacion(usados):
    calificacion = [None] * 5
    for i in range(len(usados)):
        calificacion[usados[i].puntuacion - 1].append(usados[i])
    return calificacion



def confDen():
    resp = input("Desea confirmar su compra? ")
    resp = resp.lower()
    while resp != 'si'or resp !='no':
        if resp == "si":
            m = print("Compra confirmada, gracias por usar nuestra aplicacion.")
            break
        elif resp == "no":
            m = print("Compra denegada, gracias por usar nuestra aplicacion.")
            break
        else:
            resp = input("ERROR! Ingrese respuesta vakida. Desea confirmar su compra? ")
    return m

def buscar(v,x):
    n = len(v)
    ban = False
    izq, der = 0 , n-1
    while izq <= der:
        c = (izq+der)//2
        if v[c].codigo == x:
            write(v[c])
            ban = True
            stock = int(input("Cantidad de articulos que desea comprar: "))
            if v[c].cant >= stock:
                confDen()
                break
            else:
                print("La cantidad de articulos que quiere comprar no esta disponible")

        elif x < v[c].codigo:
            der = c-1
        else:
            izq = c+1
    if ban == False:
        print("Articulo inexistente.")

def principal():
    opcion = -1
    n = validar_mayor(0, 'Ingrese cantidad de registros:')
    vec = [None] * n
    carga_automatica(vec)
    ordenar(vec)
    mostrar(vec)
    while opcion != 0:
        opcion = menu()
        if opcion == 1:
            nvos = nuevos(vec)
            ordenar_precio(nvos)
            for i in range(len(nvos)):
                write(nvos[i])
        elif opcion == 2:
            usados = usado(vec)
            usados_ = ordenar_precio(usados)
            for i in range(len(usados)):

                write(usados[i])
        elif opcion == 3:
            pass
        elif opcion == 4:
            pass
        elif opcion == 5:
            pass
        elif opcion == 6:
            pass
        elif opcion == 7:
            pass
    print('\n\n', '-' * 120)
    print(' ' * 50,'Fin del programa')











principal()