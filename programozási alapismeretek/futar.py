class Futar:
    def __init__ (self, nap, ut, km):
        self.nap = nap
        self.ut = ut
        self.km = km

def f1():
    print("\t1. Feladat\n")
    #Olvassa el a fajl adatait
    futar = []
    fbe = open("utak.txt", 'r')
    for sor in fbe:
        elem = sor.strip().split()
        nap = int(elem[0])
        ut = int(elem[1])
        km = int(elem[2])
        futar.append(Futar(nap, ut, km))
        print(elem)
    fbe.close()
    return futar

def f2(futar):
    print("\n\n\t2. Feladat\n")
    #Elso nap
    elsonap = 7
    for i in futar:
        if i.nap < elsonap:
            elsonap = i.nap
    print(elsonap)
    #Print km
    for i in futar:
        if i.nap == elsonap and i.ut == 1:
            print(" A hét első útja {} km volt.".format(i.km))
    return

def f3(futar):
    print("\n\n\t3. Feladat\n")
    #Utolso nap
    utolsonap = 1
    for i in futar:
        if i.nap > utolsonap:
            utolsonap = i.nap
    print(utolsonap)
    #Utolso ut
    utolsout = 1
    for i in futar:
        if i.nap == utolsonap and i.ut > utolsout:
            utolsout = i.ut
    print(utolsout)
    #Print km 
    for i in futar:
        if i.nap == utolsonap and i.ut == utolsout:
            print(" A hét utolsó útja {} km volt.".format(i.km))
            break
    return

def f4(futar):
    print("\n\n\t4. Feladat\n")
    munkanap = [False for i in range(7)]
    for i in futar:
        munkanap[i.nap - 1] = True
    szabadnap = 0
    for i in munkanap:
        if not i:
            szabadnap += 1
    print(" A futár {} napig nem dolgozott.". format(szabadnap))
    return

def f5(futar):
    print("\n\n\t5. Feladat\n")
    maxfuvar = 0
    for i in futar:
        if i.ut > maxfuvar:
            maxfuvar = i.ut 
    for i in futar:
        if i.ut == maxfuvar:
            print(" A maximális számú fuvar {}. napon volt.".format(i.nap))
            break
    return

def f6(futar):
    print("\n\n\t6. Feladat\n")
    napkm = [ 0 for i in range(7)]
    for i in futar:
        napkm[i.nap - 1] += i.km
    for i in range(len(napkm)):
        print(" {}. nap : {} km".format(i+1, napkm[i]))
    return

#-------------------------------------------
def fizetes(tavolsag):
    if tavolsag >= 1 and tavolsag <= 2: 
        penz = 500
    elif tavolsag >= 3 and tavolsag <= 5: 
        penz = 700
    elif tavolsag >= 6 and tavolsag <= 10:
        penz = 900
    elif tavolsag >= 11 and tavolsag <= 20: 
        penz = 1400
    elif tavolsag >= 21 and tavolsag <= 30: 
        penz = 2000
    return penz
#-------------------------------------------

def f7():
    print("\n\n\t7. Feladat\n")
    tavolsag = int(input("Adjon meg 1 és 30 km közötti távolságot."))
    penz = fizetes(tavolsag)
    print(" {} km-ért {} Ft fizetnek.".format(tavolsag, penz))
    return

def f8(futar):
    print("\n\n\t8. Feladat\n")
    fki=open('dijazas.txt','w')
    futar.sort(key=lambda x : (x.nap, x.ut))
    for i in futar:
        fki.write("{}. nap {}. út: {} Ft\n".format(i.nap, i.ut, fizetes(i.km)))
    fki.close()
    print(" Kész")
    return

def f9(futar):
    print("\n\n\t9. Feladat\n")
    osszesen = 0
    for i in futar:
        osszesen += fizetes(i.km)
    print(" A futár {} Ft kap a teljes heti munkájáért.".format(osszesen))
    return

def main():
    futar = f1()
    f2(futar)
    f3(futar)
    f4(futar)
    f5(futar)
    f6(futar)
    f7()
    f8(futar)
    f9(futar)


if __name__ == "__main__":
    main()