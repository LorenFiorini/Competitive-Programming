__author__ = 'a2'
import random

from registroPaquete import *

def conteo(v):
    cont=[0]*20
    for i in range(len(v)):
        indice=v[i].tipo
        cont[indice]+=1
    for i in range(20):
        if v[i]!=0:
            print("tipo",i,":",cont[i])

def buscar(v):
    x = int(input("Ingrese numero de identificacion: "))
    t = int(input("Ingrese importe: "))
    for i in range(len(v)):
        if v[i].identificacion == x:
            pos = i
    if v[pos].importe >= t:
        print("El paquete buscado es: ")
        display(v[pos])
    else:
        print("No existe.")


def validar(inf, sup, msj):
    x = int(input(msj + "(entre 0 y 19):"))
    while x > sup or x < inf:
        print("Error")
        x = int(input("Ingrese una op correcta:"))
    return x


def ordenar_descrip(v):
    menor = v[0].descripcion
    for i in range(len(v) - 1):
        for j in range(1, len(v)):
            if v[i].descripcion > v[j].descripcion:
                v[i].descripcion, v[j].descripcion = v[j].descripcion, v[i].descripcion


def validar_mayor(inf, msj):
    x = int(input(msj + "(mayor que " + str(inf) + "):"))
    while x <= inf:
        print("Error")
        x = int(input("Ingrese una op valida:"))
    return x


def crear_vector():
    n = int(input("Ingrese la cantidad de paquetes: "))
    v = [None] * n
    for i in range(n):
        identificacion = validar_mayor(0, "Ingrese numero de identifiacion")
        descripcion = input("Ingrese mensaje: ")
        tipo = validar(0, 19, "Ingrese el tipo ")
        dias = validar_mayor(0, "Ingrese la cantidad de dia")
        importe = validar_mayor(0, "Ingrese importe")
        v[i] = paquete(identificacion, descripcion, tipo, dias, importe)
        print("---")
    return v


def test():
    v = [None]
    op = -1
    print("1- Cargar vector")
    print("2- Mostrar vector")
    print("3- Buscar paquete")
    op = int(input("Ingrese opcion:"))

    while op != 6:

        if op == 1:
            v = crear_vector()
        if op == 2:
            if v[0] == None:
                print("El vector no fue cargado")
            else:
                ordenar_descrip(v)
                for i in range(len(v)):
                    display(v[i])
        if op == 3:
            if v[0] == None:
                print("El vector no fue cargado")
            else:
                buscar(v)
        if op == 4:
            conteo(v)

        if op == 5:
            pass
        print("1- Cargar vector")
        print("2- Mostrar vector")
        print("3- Buscar paquete")
        op = int(input("Ingrese opcion:"))


test()