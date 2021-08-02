def promedio(num, den):
    if den != 0:
        prom = num / den
        return prom
    return
def main():
    cl = contPal = contdeT = ultimaLetra = 0
    palabras_n = ci3 = item4 = 0
    tiene_n = letra_a = letra_s = re = False
    text = input('Ingrese el texto:')
    for letra in text:
        if letra == ' ' or  letra == '.':
            #Fin de palabra
            contPal += 1
            if cl > 4 and tiene_n :
                palabras_n +=1
            if letra_a and letra_s:
                ci3 += 1
            if re and ultimaLetra == 'o':
                item4 += 1
            cl = 0

            tiene_n =letra_a= letra_s = re = False
        else:
            #Dentro de palabra
            cl += 1
            if letra == 'n'or letra == 'N':
                tiene_n = True
            if (letra == 't' or letra =='T') and cl == 1:
                contdeT += 1
            if letra == 'a' or letra == 'A':
                letra_a = True
            if letra == 's' or letra == 'S':
                letra_s = True
            if letra == 'e' or letra == 'E':
                letra_a = letra_s = False
            if ultimaLetra == 'r' and letra == 'e':
                re = True
            ultimaLetra = letra
    item2 = promedio(contdeT,contPal)

    print('Palabras con mas de cuatro letras y con al menos una "n":',palabras_n)
    print('CANTIDAD DE PALABRAS QUE TIENE EL TEXTO:',contPal)
    print('promedio de letras por palabra entre las que comenzaban con "t":',item2)
    print('palabras contienen una "a" y tambien una "s", pero no contienen una "e":',ci3)
    print('palabras contienen al menos una vez la expresión "re" pero terminaban con la letra "o":',item4)

main()
