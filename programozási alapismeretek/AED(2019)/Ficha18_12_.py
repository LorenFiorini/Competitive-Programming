'''Desarrollar un programa que permita obtener estadísticas para el Hipódromo.

Para comenzar, se debe cargar un vector de n registros (n se ingresa por teclado).
Cada registro representa una apuesta realizada para una cierta carrera, con los siguientes datos:
número de ticket, caballo elegido (un número del 0 al 9, validar) y monto a apostar.

Luego, implementar un menú con las siguientes opciones:

    -Determinar el monto total de apuestas para cada caballo
    -Buscar un ticket cuyo número se ingresa por teclado. Si no existe, informarlo.
     Si existe, multiplicar por 10 el monto apostado y mostrar los datos de la apuesta.
    -Contar cuántas apuestas se realizaron para un cierto número de caballo, que se ingresa por teclado
    -Mostrar los datos del ticket con mayor monto apostado
'''
from apuesta import *
import random



def validar_mayor_cero(msm):
    valor = int(input(msm))
    while valor < 0:
        print('Error!!! El valor a ingresar debe ser mayo a 0')
        valor = int(input(msm))
    return valor

def validar_entre(msm, limSup, limInf):
    valor = int(input(msm))
    while valor < limInf or valor > limSup:
        print('Error!!! Ingresar un valor en el rango ')
        valor = int(input(msm))
    return valor

def cargar_vector(vector):
    for i in range(len(vector)):
        numero = validar_mayor_cero('Ingrese el numero de ticket')
        caballo = validar_entre('Ingrese el caballo', 0, 9)
        monto = validar_mayor_cero('Ingresar el monto')
        #Generar el registro
        apuesta = Apuesta(numero,caballo,monto)
        #Asignar el registro al vector
        vector[i] = apuesta

def acumular_por_caballo(vector):
    v = [0] * 10
    for apuesta in vector:
        v[apuesta.caballo] += apuesta.monto
    return v


def buscar(vector, numero):
    pos = -1
    for i in range (len(vector)):
        if vector[i].numero == numero:
            pos = i
            break
    return  pos


def contar_apuestas(vector, cab):
    contar = 0
    for apuesta in vector:
        if apuesta.caballo == cab:
            contar += 1
    return contar

'''
def buscar_mayor(numero, monto):
     mayor = [None]
     for i in range(len(monto)):
         if mayor is None:
             mayor = monto [0]
             pos = numero[i]
         elif monto[i] > mayor:
             mayor = monto[i]
             pos = numero[i]
     return mayor'''

def buscar_mayor (vector):
    mayor = vector[0]
    for i in range ( 1,len(vector)):
        if vector[i].monto > mayor.monto:
            mayor = vector [i]
    return mayor


def principal():
    n = validar_mayor_cero('Ingrese cantidad de apuestas:')
    vector = [None] * n
    cargar_vector(vector)
    opcion = -1
    while opcion != 0:
        print('Menu de opciones')
        print('=' * 60)
        print('1_ Monto total por caballo')
        print('2_ Buscar ticket')
        print('3_ Cantidad de apuestas de un caballo')
        print('4_ Mostrar ticket con mayor monto apostado')
        print('0_ Salir')
        if opcion == 1:
            vectorAcumulacion = acumular_por_caballo(vector)
            for i in range(len(vectorAcumulacion)):
                print("Caballo",i,"Total de apuestas: ", vectorAcumulacion[i])
        elif opcion == 2:
            numero = validar_mayor_cero("Ingrese el numero de ticket: ")
            pos = buscar(vector,numero)
            if pos == -1:
                print("No hay apuesta con ese numero.")
            else:
                apuesta = vector[pos]
                apuesta.monto *= 10
                write(apuesta)
        elif opcion == 3:
            cab = validar_entre("Ingrese el numero del caballo: ",0,9)
            cantidad = contar_apuestas(vector,cab)
            print("La cantidad de apuestas del caballo ", cab, "fueron", cantidad)
        elif opcion == 4:
            ticket = buscar_mayor(vector)
            print("El monto mas grande es:", ticket)

