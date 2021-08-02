
class Articulo:
    def __init__(self, codigo, precio, provincia, estado, cantidadDisponible, puntuacionVendedor):
        self.codigo = codigo
        self.precio = precio
        self.prov = provincia
        self.estado = estado
        self.cant = cantidadDisponible
        self.puntuacion = puntuacionVendedor



def write(articulo):
    print('Codigo:', articulo.codigo, end=' ')
    print('- Precio $', articulo.precio, end=' ')
    print('- Provincia:', articulo.prov, end=' ')
    print('- Estado:', articulo.estado, end=' ')
    print('- Cantidad disponible:', articulo.cant, end=' ')
    print('- Puntuacion del vendedor:', articulo.puntuacion, end='\n')


