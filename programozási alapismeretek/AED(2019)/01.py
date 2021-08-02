def vocal(car):
    vocales = 'aeiou'
    if car in vocales:
        return True
    return False

def principal ():
    print('Procesaminto de texto ejercicio 5')
    texto = input('Ingresar por teclado, con palabras separadas por un espacio y terminado en punto: ')
    texto = texto.lower()
    tieneM = tieneB = primeraP = peYvocal = False
    palabrasConMyb = letrasPalabra = contador_pYvocal = contadorCapicua = 0

    for car in texto:
        if car == ' ' or car == '.':
            #fin palabra
            if primera == ultimaLetra and letrasPalabra > 1:
                contadorCapicua += 1
            if tieneM and tieneB:
                palabrasConMyb += 1
            if peYvocal:
                contador_pYvocal += 1
            tieneB = tieneM = primeraP = peYvocal = False
            letrasPalabra = 0
        else:
            letrasPalabra += 1
            if letrasPalabra >= 3:
                if car == 'm':
                    tieneM = True
                if car == 'b':
                    tieneB = True
            if letrasPalabra == 1 and car == 'p':
                primeraP = True
            if letrasPalabra == 2 and primeraP and vocal(car):
                peYvocal = True
            if letrasPalabra == 1:
                primera = str(car)
            ultimaLetra = str(car)



    print('Palabras tienen una m y una b a partir de la tercer letra:', palabrasConMyb)
    print('Palabras comienzan con la letra p seguida de cualquier vocal:', contador_pYvocal)
    print('Palabras comienzan y terminan con el mismo caracter:', contadorCapicua)
    #Mi amiga Ambar siempre piensa y cambia pronto.



principal()