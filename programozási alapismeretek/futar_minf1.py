#az adatok nem időrendben (nem időrendi sorrendben) vannak
print('1. feladat')
futar=[] #létrehozunk 1 új üres listát
#ebbe a listába olvassuk be a txt fájl tartalmát
fbe=open('utak.txt','r') #megnyitjuk a txt fájl tartalmát olvasásra (read módra)
for sor in fbe:
    elem=sor.strip().split() #elemeire bontjuk a sorokat
    nap=int(elem[0])
    ut=int(elem[1])
    km=int(elem[2])
    #így az elemek külön számként használhatók
    futar.append([nap,ut,km])
    #hozzáfűzzük az eddigi listához az új sor elemeit, míg el nem fogy
fbe.close()
print(futar) #ellenőrzés céljából printelünk a képernyőre
 
print('\n2. feladat')
#keressük a minimális napot, azon belül az 1. út hosszát km-ben.
#minimum keresése napra:
elsonap=7 #indulunk egy irreálisan értéktől
#7-ről indulunk vissza, mert egy hétről szól a feladat
for i in futar:
    if i[0]<elsonap:
        elsonap=i[0]
#print(elsonap)
#már ismert az első nap
#biztos, hogy a nap első útja 1. számú
#keressük az első nap 1. útjához tartozó km-t
for i in futar:
    if i[0]==elsonap and i[1]==1:
        print('A hét első útja %s km volt.' %(i[2]))

print('\n3. feladat')
#keressük a maximális napot, azon belül az utolsó út hosszát km-ben
#az utolsú jelentése a kódban: maximális sorszámú út
#FONTOS: az utolsó naphoz tartozó utolsó út =max nap max útja
#maximum keresése napra:
utolsonap=1
for i in futar:
    if i[0]>utolsonap:
        utolsonap=i[0]
#print(utolsonap)
#most kell keresni az utolsó nap utolsó útját
utolsout=1
for i in futar:
    if i[0]==utolsonap:
        #ez a feltétel biztosítja azt, hogy az utolsó napon belüli utolsó utat (max utat) találjuk
        if i[1]>utolsout:
            utolsout=i[1]
#print(utolsout)
for i in futar:
    if i[0]==utolsonap and i[1]==utolsout:
        print('A hét utolsó útja %s km volt.' %(i[2]))

print('\n4. feladat')
#célszerű halmazokkal (set) dolgozni
napok={1,2,3,4,5,6,7}
#tervezett stratégia:
#készítünk egy set-et a futár munkanapjaiból: munkanap
#szabadnapok megkapjuk a napok-munkanapok halmazok különbségéből
munkanap=set()
for i in futar:
    munkanap.add(i[0]) #üres halmaz feltöltése
#print(munkanap)
szabadnap=napok-munkanap
#kiírási cél: A futár szabadnapjai: 2, 6, 
print('A futár szabadnapjai: ',end='')
for i in szabadnap:
    print(i,end=', ') #end=', ': a print a nyomtatás után nem kerül új sorba
#print a parancs végén sort emel (=új sorba megy a kurzor)
print()
#az előbbi soremelés nélküli printvisszaállítása olyan parancsra, mely a végén új sorba megy,
#így lesz értelme: \n által kiírt üres sornak

print('\n4. feladat, B. megoldás')
#B stratégia: napok, ameleyk nincsenek a munkanapban (not in) = a futár szabadnapjai
#felhasználjuk az előző megoldásból: napok, munkanap
print('A futár szabadnapjai: ',end='')
for i in napok:
    if i not in munkanap:
        print(i,end=', ')
print()        

print('\n5. feladat')
#legtöbb fuvar=legtöbb út
#maximum keresése útra
utmax=1
for i in futar:
    if i[1]>utmax:
        utmax=i[1]
print(utmax)
#most megkeressük az utmax-hoz tartozó napot
for i in futar:
    if i[1]==utmax:
        print('Az %s. napon volt a futárnak a legtöbb útja.' %(i[0]))

print('\n5. feladat, B. megoldás')
utmax=1
utmaxnap=1
for i in futar:
    if i[1]>utmax:
        utmax=i[1]
        utmaxnap=i[0]
print('Az %s. napon volt a futárnak a legtöbb útja.' %(utmaxnap))

print('\n6. feladat')
#szétválogatjuk napokra a lista sorait: for-for-if
#for: amely listára szétválogatunk -->napok
#   for: amely listát szétválogatjuk -->futar
#       if: amely összekapcsolja két for ciklus adatait: nap

#összegzés km-re
for nap in napok:
    napikm=0  #minden nap 0-ról indul a napikm
    for i in futar:
        if nap==i[0]:
            napikm+=i[2]
    print('%s. nap: %s km' %(nap,napikm))
            































