class candidate:
    def __init__ (self, kerulet, szavazatok, vezeteknev, utonev, part):
        self.kerulet = int(kerulet)
        self.szavazatok = int(szavazatok)
        self.vezeteknev = vezeteknev
        self.utonev = utonev
        self.part = part



def f1 ():
    print("\t1. feladat\n")
    szavazas = []
    resztvevo = 0
    fbe = open('szavazatok Minf.txt', 'r')
    for sor in fbe:
        temp = sor.strip().split()
        kerulet = int(temp[0])
        szavazatok = int(temp[1])
        vezeteknev = temp[2]
        utonev = temp[3]
        part = temp[4]
        szavazas.append(candidate(kerulet, szavazatok, vezeteknev, utonev, part))
        
        resztvevo += szavazatok
        print(temp)
    fbe.close()
    return szavazas, resztvevo


def f2 (s):
    print("\n\n\t2. feladat\n")
    print(" A helyhatósági választáson %s képviselőjelölt indult.\n" %len(s))
    return
    

def f3(szavazas):
    print("\n\t3. feladat\n")
    jo = False
    while not jo:
        vezeteknevbe = input("Kérem a vezetéknevet: ")
        utonevbe = input("Kérem az utónevet: ")
        for i in szavazas:
            if i.vezeteknev == vezeteknevbe and i.utonev == utonevbe:
                print(" A visgált személy %s szavazatot kapott." %i.szavazatok)
                jo = True
        if not jo:
            tmp = -1
            while tmp != 0 and tmp != 1:
                print("Ilyen nevű képviselőjelölt nem szerepel a nyilvántartásban!")
                tmp = int(input("Szeretne újra keresni(1:Igen / 0:Nem): "))
                if tmp == 0:
                    jo = True
    return
    
def f4(fo, resztvevo):
    print("\n\n\t4. feladat\n")
    txt = " A választáson {} állampolgár, a jogosultak {:.2f}%-a vett részt.\n"
    print(txt.format(resztvevo, resztvevo / fo * 100))
    return

def f5(szavazas,resztvevo):
    print("\n\t5. feladat\n")
    partok = {
        'PP' : 0,
        'SP' : 0,
        'ZP' : 0,
        'KP' : 0,
        '-' : 0
    }
    for i in szavazas:
        partok[i.part] += i.szavazatok
    print(' Piros Párt = %.2f%%' %(partok['PP'] / resztvevo * 100))
    print(' Sárga Párt = %.2f%%' %(partok['SP'] / resztvevo * 100))
    print(' Zöld Párt = %.2f%%' %(partok['ZP'] / resztvevo * 100))
    print(' Kék Párt = %.2f%%' %(partok['KP'] / resztvevo * 100))
    print(' Független jelöltek = %.2f%%' %(partok['-'] / resztvevo * 100))
    return

def f6(szavazas,resztvevo):
    print("\n\t6. feladat\n")
    maxszavazat = max(szavazas.szavazatok)
    print(maxszavazat)
    for i in szavazas:
        if i.szavazatok == maxszavazat:
            print("%s %s".format(i.))



def main():
    fo = 12345
    szavazas, resztvevo = f1()
    f2(szavazas)
    f3(szavazas)
    f4(fo, resztvevo)
    f5(szavazas, resztvevo)
    
if __name__ == "__main__":
    main()
