'''Por cada socio, se pide guardar su número de identificación, su
nombre, el arancel que paga cada mes y un código entre 0 y 9
para indicar el deporte que cada socio practica (suponiendo
que por ejemplo, el 0 puede ser fútbol, el 1 básquet, y así hasta
el código 9).'''

'''Se pide desarrollar un programa en Python controlado por un
menú de opciones. Ese menú debe permitir gestionar las
siguientes tareas a partir del arreglo pedido en el párrafo
anterior:
1- Cargar el arreglo pedido con los datos de los n socios. Sólo
valide el código del deporte practicado, para asegurar que esté
entre 0 y 9.
2- Mostrar los datos de todos los socios que paguen un arancel
mayor a p, siendo p un valor que se carga por teclado.
3- Mostrar el mayor arancel que se abona en el club.
4- Mostrar todos los datos, ordenados de menor a mayor por
número de identificación.
5- Determinar si existe algún socio cuyo nombre sea igual a x,
siendo x una cadena que se carga por teclado. Si existe,
cambiar el valor del campo arancel de forma de sumarle un
valor fijo de 100 pesos, y mostrar todos los datos de ese socio
por pantalla. Si no existe, informar con un mensaje.
6- Buscar en el arreglo el socio cuyo número de identificación
sea igual a x, siendo x un valor pasado por parámetro.
7- Determinar y mostrar cuántos socios practican cada tipo de
deporte posible (un contador para contar cuántos socios
practican el deporte 0, otro para los que practican el deporte 1,
etc.).'''
import random
class Socio:
    def __init__(self, id, nom, ara, dep):
        self.identificacion = id
        self.nombre = nom
        self.arancel = ara
        self.deporte = dep

def write(socio):
    print("Identificacion:", socio.identificacion,"-",end=" ")
    print("Nombre:", socio.nombre,"-",end=" ")
    print("Arancel:", socio.arancel,"-",end=" ")
    print("Deporte:", socio.deporte)

