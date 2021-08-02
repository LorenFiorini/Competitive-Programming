__author__ = 'a2'


class paquete():
    def __init__(self, id, des, tip, d, imp):
        self.identificacion = id
        self.descripcion = des
        self.tipo = tip
        self.dias = d
        self.importe = imp

def display(paquete):
    print("Identificacion",paquete.identificacion,"Descripcion: ",paquete.descripcion,"Tipo: ", paquete.tipo, "Dias: ", paquete.dias,"Importe: ", paquete.importe)
