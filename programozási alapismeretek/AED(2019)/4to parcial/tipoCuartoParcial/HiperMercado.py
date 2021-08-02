
import os
import pickle

class Producto:
    def __init__(self, cod, nom, tipo, precio, stock, origen):
        self.codigo = cod
        self.nombre = nom
        self.tipo = tipo
        self.precio = precio
        self.stock = stock
        self.origen = origen


def display(producto):
    print('Codigo: ', producto.codigo, end='')
    print('| Nombre: ', producto.nombre, end='')
    print('| Tipo: ', producto.tipo, end='')
    print('| Precio: ', producto.precio, end='')
    print('| Stock: ', producto.stock, end='')
    print('| Origen: ', producto.origen)

# Punto 1
# Cargar los datos de n registros de tipo Producto
# en un archivo llamado "Productos.dat" (cargue n por teclado).
# Puede cargar los datos manualmente, o puede generarlos aleatoriamente.


# Punto 2
# Mostrar el archivo creado en el punto anterior,
# a razón de un registro por línea en la pantalla.

def leerArchivo(archivo):
    if not os.path.exists(archivo):
        print('Archivo inexixtente')
        return
    m = open(archivo,'rb')
    tam = os.path.getsize(archivo)
    while m.tell() < tam:
        prod = pickle.load(m)
        display(prod)
    m.close()

# Punto 3
# A partir del archivo creado en el punto 1, generar un vector de conteo
# que cuente la cantidad total (considerando el stock) de productos
# por cada tipo de producto.
# Muestre solo las cantidades mayores a cero.


# Punto 4
# A partir del archivo, crear un vector de registros en el cual
# se copien los datos de todos los productos cuyo precio
# unitario sea mayor a un valor x que se carga por teclado.
# Muestre por pantalla los datos del vector, a razón de un
# registro por línea de pantalla.

def generarVector(archivo,x):
    if not os.path.exists(archivo):
        print('Archivo inexixtente')
        return
    m = open(archivo,'rb')
    vec = []
    tam = os.path.getsize(archivo)
    while m.tell() < tam:
        prod = pickle.load(m)
        if prod.precio > x:
           vec.append(prod)
    m.close()
    return vec

def mostrarVector(vec):
    for i in range(len(vec)):
        display(vec[i])

# Punto 5
# Generar a partir del vector, del punto 4, una matriz
# donde cada componente representa la cantidad de productos
# de tipo i y de origen j que posee el negocio.
# Seguidamente, visualice los datos por pantalla.

def generarMatriz(vec):
    mat = [[0]* 20 for filas in range(10)  ]

    for i in range(len(vec)):
        fil= vec[i].tipo -1
        col= vec[i].origen -1
        mat[fil][col] += 1

    return mat

def generarMatriz_desdeArchivo():
    if not os.path.exists('Productos.dat'):
        print('Archivo inexistente')
        return
    mat = [[0]* 20 for filas in range(10)  ]
    m = open('Productos.dat','rb')
    tam = os.path.getsize('Productos.dat')
    while m.tell() < tam:
        prod = pickle.load(m)
        fil= prod.tipo -1
        col= prod.origen -1
        mat[fil][col] += 1
    m.close()
    return mat

def mostrarMatriz(mat):
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            print('Tipo ', i+1, ' Origen ', j+1, ': ', mat[i][j])
# Punto 6
# A partir del vector generado en el punto 4, determine
# la cantidad de productos que tienen el mayor
# precio unitario.
# Pueden existir varios productos con el mismo mayor precio
# unitario.
