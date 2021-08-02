def vocal(letra):
    vocales = 'aeiouAEIOU'
    if letra in vocales:
        return True
    return  False

def porcentaje(parte, total):
    return parte * 100 / total

def main():
    text = input('Ingrese un texto:')
    contadorLetra = contadorPalabra = cantVocal = item1 = item3 = ultimaLetra = tieneGA = posicion = 0
    menorPalabra = 100
    consonanteSegunda = empiezaVP = False
    for letra in text:
        if letra ==' ' or letra =='.':
            contadorPalabra += 1
            if cantVocal >= 3 and contadorLetra > 4:
                item1 += 1
            if contadorLetra < menorPalabra and consonanteSegunda:
                menorPalabra = contadorLetra
            if empiezaVP and (ultimaLetra == 'n' or ultimaLetra == 'N' or ultimaLetra == 'a' or ultimaLetra == 'A'):
                item3 += 1
            contadorLetra = cantVocal = 0
            consonanteSegunda = empiezaVP = False
        else:
            contadorLetra += 1
            if vocal(letra):
                cantVocal += 1
            if contadorLetra == 2 and not vocal(letra):
                consonanteSegunda = True
            if (letra == 'v' or letra == 'V' or letra == 'p' or letra == 'P') and contadorLetra == 1:
                empiezaVP = True
            if letra == 'g' or letra == 'G':
                posicion = contadorLetra
            if (letra == 'a' or letra == 'A') and posicion == (contadorLetra - 1):
                tieneGA += 1
            ultimaLetra = letra
    item4 = porcentaje(tieneGA, contadorPalabra)

    print('Palabras tienen por lo menos tres vocales y mas de cuatro letras:',item1)
    print('Longitud de la palabra mas corta de entre las que contienen una consonante en la segunda posicion:',menorPalabra)
    print('Palabras que empiezan con "v" o con "p" y terminan con "n" o con "a":',item3)
    print('Porcentaje de palabras que contenian la expresion "ga" con respecto al total del palabras del texto:', item4)

main()