class Call():
    def __init__(self, oraK, percK, mpercK, oraV, percV, mpercV, telefonszam):
        self.oraK = oraK 
        self.percK = percK 
        self.mpercK = mpercK
        self.oraV = oraV
        self.percV = percV 
        self.mpercV = mpercV 
        self.telefonszam = telefonszam 

def f1():
    print("\n\t1. Feladat\n")
    telefonszam = input("Kérem a telszámot: ")
    kezd = int(telefonszam[0]) * 10 + int(telefonszam[1])
    if kezd == 39 or kezd == 41 or kezd == 71:
        print(" Ez vezetékes szám.")
    else: 
        print(" Ez NEM vezetékes szám.")
    return

def f2():
    print("\n\t2. Feladat\n")
    time = {
        "kezdő óráját" : 0,
        "kezdő percét" : 0,
        "kezdő másodpercét" : 0,
        "végső óráját" : 0,
        "végső percét" : 0,
        "végső másodpercét" : 0
    }
    for i in time:
        txt = "\n Kérem a hívás {}: ".format(i)
        time[i] = int(input(txt))

    percek = 0
    percek += 60 * (time["végső óráját"] - time["kezdő óráját"])
    percek += time["végső percét"] - time["kezdő percét"]
    if time["végső másodpercét"] > time["kezdő másodpercét"]:
        percek += 1
    print("A beszélgetés, számlázás szempontjából {} percig tartott.".format(percek))


def main():
    f1()
    f2()



if __name__ == "__main__":
    main()