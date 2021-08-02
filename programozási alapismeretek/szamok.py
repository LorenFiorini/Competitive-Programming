#fájl (file) beolvasása:
szamok=[] #üres lista inicializálása
fbe=open('adat.txt','r')
for sor in fbe:
    sor=int(sor.strip())
#strip() letisztítja a sorokat a sorvégi jelektől (soremelés, sor elejére jel (CR))
    szamok.append(sor)
fbe.close()
print(szamok)
print(min(szamok), max(szamok))
print(sorted(szamok))
print(sorted((szamok),reverse=True))
