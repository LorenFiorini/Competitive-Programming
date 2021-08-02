import time
import random
def principal():
    inicio = time.time()
    segundos = time.time() - inicio
    while segundos < 15:
        entradas = random.randint(0,10)
        time.sleep(1)
        print('Se vendieron',entradas,'en la hora',segundos)
        segundos = time.time() - inicio

principal()