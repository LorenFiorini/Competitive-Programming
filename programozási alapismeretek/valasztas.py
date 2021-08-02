SZAVAZHATNAK=12345

print('1. feladat')
#lista létrehozása:
szavazas=[]
#file megnyitása "olvasás" módra
fbe=open('szavazatok Minf.txt','r')
for sor in fbe: #soronként végigmegyünk a file-on
    elem=sor.strip().split()
    #strip(): a sor végén lévő jeleket "letisztítja":
    #- soremelés
    #- kocsi vissza (CR= carriage return)
    #split(): szóköz (space) mentén szeletel (szétvág)
    kerulet=int(elem[0])
    szavazatok=int(elem[1])
    vezeteknev=elem[2]
    utonev=elem[3]
    part=elem[4]
    #elemek hozzáfűzése a listához soronként:
    szavazas.append([kerulet,szavazatok,vezeteknev,utonev,part])  
fbe.close()
print(szavazas)

print('\n2. feladat')
print('A helyhatósági választáson',len(szavazas),' képviselőjelölt indult.')
print('A helyhatósági választáson %s képviselőjelölt indult.'%(len(szavazas))) #:)

print('\n3. feladat')
vezeteknevbe=input('Kérem a vezetéknevet: ')
utonevbe=input('Kérem a utónevet: ')

#soronként végigmegyünk a listán, keressük a 2. és 3. indexű elem egyezését:
van=False #logikai változó, boolean
#minden változót kezdetben inicializálni kell

for i in szavazas:
    if i[2]==vezeteknevbe and i[3]==utonevbe:
        print('A vizsgált személy %s szavazatot kapott.' %(i[1]))
        van=True
if van==False:
    print('Ilyen nevű képviselőjelölt nem szerepel a nyilvántartásban!')

print('\n4. feladat')
#öSSZEGZÉS:
sumszavazat=0
for i in szavazas:
    sumszavazat+=i[1] #sumszavazat=sumszavazat+i[1]
print(sumszavazat)
#részvételi arány: sumszavazat/SZAVAZHATNAK*100
print('A választáson %s állampolgár, a jogosultak %.2f%%-a vett részt.' %(sumszavazat,sumszavazat/SZAVAZHATNAK*100))
# %.2f: 2 tizedes pontossággal (2 tizedesjeggyel)
# %%: a % foglalt jel, ezért "el kell takarni" önmagával

print('\n5. feladat')
pirosdb=0
sargadb=0
zolddb=0
kekdb=0
fuggetlendb=0
for i in szavazas:
    if i[4]=='PP':
        pirosdb+=i[1]
    elif i[4]=='SP':
        sargadb+=i[1]
    elif i[4]=='ZP':
        zolddb+=i[1]
    elif i[4]=='KP':
        kekdb+=i[1]
    else:
        fuggetlendb+=i[1]
print('Piros Párt = %.2f%%' %(pirosdb/sumszavazat*100))
print('Sárga Párt = %.2f%%' %(sargadb/sumszavazat*100))
print('Zöld Párt = %.2f%%' %(zolddb/sumszavazat*100))
print('Kék Párt = %.2f%%' %(kekdb/sumszavazat*100))
print('Független jelöltek = %.2f%%' %(fuggetlendb/sumszavazat*100))




    
        
