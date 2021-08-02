import random
from Problema49_modulo import *
def validarEntre(minimo,maximo, mensaje):
    n = int(input(mensaje))
    while n < minimo or n > maximo:
        print('Error!')
        n = int(input(mensaje))
    return n


def cargar_vector(vec):
    for i in range(len(vec)):
        id = input("Ingrese el numero de identificacion: ")
        nombre = str(input('Ingrese su nombre: '))
        arancel = float(input('Arancel:'))
        codigo = validarEntre(0, 9, "Ingrese un codigo entre 0 y 9: ")
        vec[i]= Socio(id ,nombre, arancel, codigo)


def item2(vec,p):
    for i in range(len(vec)):
        if vec[i].arancel > p:
            write(vec[i])

def item3(vec):
    mayor = vec[0].arancel
    for i in range(1, len(vec)):
        if vec[i].arancel > mayor:
            mayor = vec[i].arancel
    return mayor

def ordenarPorNumero(vec):
    n = len(vec)
    for i in range(n-1):
        for j in range(i+1, n):
            if vec[i].identificacion > vec[j].identificacion:
                vec[i], vec[j] = vec[j], vec[i]

def buscarPorNombre(vec, x):
    ban = False
    for i in range(len(vec)):
        if vec[i].nombre == x:
            vec[i].arancel += 100
            write(vec[i])
            ban = True
    if ban == False:
        print("Socio inexistente")

def buscarPorNumero(vec, x):
    ordenarPorNumero(vec)
    n = len(vec)
    izq, der = 0, n-1
    while izq <= der:
        c = (izq + der) // 2
        if vec[c].identificacion == x:
            return vec[c]
        elif x < vec[c].identificacion:
            der = c-1
        else:
            izq = c+1
    return


def principal():
    n = int(input("Cantidad de  socios: "))
    vec = [None] * n
    ban = False
    opcion = -1
    while opcion != 0:
        opcion = validarEntre(0, 7, 'Ingrese una opcion valida entre 0 y 7: ')
        if opcion == 1:
            cargar_vector(vec)
            for i in range(len(vec)):
                write(vec[i])
            ban = True
        elif opcion == 2:
            if ban == True:
                p = float(input("Ingrese arancel a comparar: "))
                item2(vec,p)
            else:
                print("Sin datos")
        elif opcion == 3:
            if ban == True:
                item3(vec)
            else:
                print("Sin Datos")
        elif opcion == 4:
            if ban == True:
                ordenarPorNumero(vec)
                for i in range(len(vec)):
                    write(vec[i])
            else:
                print("Sin datos")
        elif opcion == 5:
            if ban == True:
                x = input("Ingrese el nombre a buscar")
                buscarPorNombre(vec,x)
            else:
                print("Sin datos")
        elif opcion == 6:
            if ban == True:
                x = int(input("Ingrese num a buscar: "))
                var = buscarPorNumero(vec, x)
                if var == None:
                    print("Socio inexistente")
                else:
                    write(var)
            else:
                print("Sin datos")
        elif opcion == 7:
            pass
    print("Fin del proceso")

principal()