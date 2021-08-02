__author__ = 'a2'
'''Desarrollar un programa que permita cargar un arreglo con las alturas de n personas.
 Determinar la altura media del grupo,e informar cuantas de esas personas tienen una
altura mayor a la media, y cuantas tienen una altura menor igual a la media.'''

def validarMayorQue(menor):
    n = int(input('Ingrese el numero de personas:'))
    while n <= menor:
        print('Error ingrese un numero mayor a cero')
        n = int(input('Ingrese el numero de personas:'))
    return n

def promedio(v):
    acumulador = 0
    for i in range(len(v)):
        acumulador += v[i]
    a = acumulador / len(v)
    return a

def cargaDatos(v):
    for i in range(len(v)):
        v[i] = validarEntre(0, 3)

def compararMedia(v, prom):
    contadorMayor = contadorMenor = 0
    for i in range(len(v)):
        if v[i] > prom:
            contadorMayor += 1
        else:
            contadorMenor += 1
    return contadorMayor, contadorMenor

def validarEntre(limInferior, limSuperior):
    n = float(input('Ingrese la altura de la persona(en metros):'))
    while n < limInferior or n > limSuperior:
        print('Error ingrese una altura valida(entre cero y tres)')
        n = float(input('Ingrese la altura de la persona(en metros):'))
    return n

def main():
    n = validarMayorQue(0)
    v = n *[0]
    cargaDatos(v)
    prom = promedio(v)
    mayor, menorIgual = compararMedia(v, prom)
    print('La altura promedio es', prom)
    print('Contador de personas con altura mayor a la media:', mayor)
    print('Contador de personas con altura menor a la media:', menorIgual)


main()