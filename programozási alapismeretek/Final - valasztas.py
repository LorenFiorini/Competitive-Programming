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

#Pythonban a tömbök típusai: lista=list (és halmaz=set), szótár=dict, tuple=tuple.
#Mi a listával és halmazzal fogunk dolgozni.

print('\n2. feladat')
#\n szerepe a printben: új üres sor, így átlathatóbb a kód futtatása
print('A helyhatósági választáson',len(szavazas),' képviselőjelölt indult.')
print('A helyhatósági választáson %s képviselőjelölt indult.'%(len(szavazas)))
#Annyi fő indult, ahány sor van a txt-ben, vagyis a listában,
#tehát: a ltxt sorainak száma, vagyis alista hossza
#hossz=lenght, pythonban: len.

print('\n3. feladat')
vezeteknevbe=input('Kérem a vezetéknevet: ')
utonevbe=input('Kérem a utónevet: ')

#soronként végigmegyünk a listán, keressük a 2. és 3. indexű elem egyezését:
van=False #logikai változó,
#logikai változónak (boolean változónak) csak 2 értéke van: igaz (True) és hamis (False)
#így mint egy kapcsoló viselkedik a programban, vagyis egy jel tud lenni.

for i in szavazas: #soronként végigmegy a "szavazas" listán
    if i[2]==vezeteknevbe and i[3]==utonevbe:
        print('A vizsgált személy %s szavazatot kapott.' %(i[1]))
        van=True
#Ha a jel értéke igaz lett, akkor van találat,
#ha a jel értéke a kezdeti hamis maradt, akkor nincs találat.
#minden változót kezdetben inicializálni kell:
if van==False:
    print('Ilyen nevű képviselőjelölt nem szerepel a nyilvántartásban!')

print('\n4. feladat')
#öSSZEGZÉS:
#kezdeti=induló értékkel inicializálunk (általában 0)
sumszavazat=0
for i in szavazas: #soronként végigmegy a "szavazas" listán
    sumszavazat+=i[1] #sumszavazat=sumszavazat+i[1]
print(sumszavazat)
#részvételi arány: sumszavazat/SZAVAZHATNAK*100
print('A választáson %s állampolgár, a jogosultak %.2f%%-a vett részt.' \
      %(sumszavazat,sumszavazat/SZAVAZHATNAK*100))
# %.2f: 2 tizedes pontossággal (2 tizedesjeggyel)
# %%: a % foglalt jel, ezért "el kell takarni" önmagával

print('\n5. feladat')
#összegzés:
pirosdb=0
sargadb=0
zolddb=0
kekdb=0
fuggetlendb=0
for i in szavazas: #soronként végigmegy a "szavazas" listán
    if i[4]=='PP':
        pirosdb+=i[1] #pirosdb=pirosdb+i[1]
    elif i[4]=='SP': #elif=else if
        sargadb+=i[1]
    elif i[4]=='ZP':
        zolddb+=i[1]
    elif i[4]=='KP':
        kekdb+=i[1]
    else:#a végén, ha már nincs egyéb eset, akkor használhatunk else ágat.
        fuggetlendb+=i[1]
#Ennél a feladatrésznél a szavazáson szereplő létszámhoz arányítunk (viszonyítunk).
print('Piros Párt = %.2f%%' %(pirosdb/sumszavazat*100))
print('Sárga Párt = %.2f%%' %(sargadb/sumszavazat*100))
print('Zöld Párt = %.2f%%' %(zolddb/sumszavazat*100))
print('Kék Párt = %.2f%%' %(kekdb/sumszavazat*100))
print('Független jelöltek = %.2f%%' %(fuggetlendb/sumszavazat*100))

print('\n6. feladat')
#legtöbb szavazat=maximális szavazat keresése a feladat
#a txt vizsgálata után 288 lesz az eredmény
#MAXIMUM keresése:
#kezdeti=induló értékkel inicializálunk, amely irreálisan kicsi.
#Ha MINIMUM keresés lenne a feladat, akkor irreálisan nagy induló értékkel kezdünk.
maxszavazat=0 #irreálisan kicsi, hogy 0-val nyer.
for i in szavazas: #soronként végigmegy a "szavazas" listán
    if i[1]>maxszavazat: #ha bármelyik szavazat (i[1]) nagyobb, mint az aktuális maxszavazat
        maxszavazat=i[1] #maxszavazat vegye fel az értékét az éppen vizsgált i[1]-nek
#0->19; 19->120; 120->162; 162->162 (marad); 162->162 (marad); 162->162 (marad); 162->188;
#majd 6 soron marad: 188->188; 188->288, mely érték a vizsgálat végéig megmarad,
#tehát a maximum=288.
#Mivel a maximális szavazathoz tartozó nevek és pártjelek szükségesek print-hez,
#ismét végigmegyünk a listán (for)
print(maxszavazat)
#ha nincs kész egy ciklus, de print-tel tesztelni szeretnénk, akkor "pass"-írunk (passzolunk).
print('A legtöbb szavazatot kapta:')
#ha a fix szöveg print-je a for ciklus előtt van, akkor a print-ben lévő szöveg csak egyszer jelenik meg,
#és nem jelenik meg minden if teljesülésekor (feladatunkban 3-szor).
for i in szavazas:
    if i[1]==maxszavazat: #ez az if csak azoknál a soroknál állítja meg a ciklust, ahol szavazat: 288. 
        if i[4]=='-':
        #ez az elágazás oldja meg azt a feladatrészt, mely a "-" pártrövidítés helyett kiírja: "független"
            print('%s %s: független' %(i[2],i[3]))
        else:
            print('%s %s: %s' %(i[2],i[3],i[4]))

print('\n7. feladat')
#azok lettek képviselők a kerületekben, akik a kerületen belül a legnagyobb (max) szavazatot kapták.
#szétválogatjuk kerületekre a szavazásokat,
#a szétválogatott szavazatok között keressük a max-ot.
#for-for-if lesz:
#for: rögzíti a kerületeket 1-8 (külső for ciklus)
#   for: végigmegy a listán annyiszor, ahány kerület van, itt 8-szor (belső for ciklus)
#       if: amely if figyeli, hogy a lista aktuális sora az éppen vizsgált kerületben van-e.
fki=open('kepviselok.txt','w')
#megnyitottuk a kepviselok.txt fájl írásra (write mode: w)
for kerulet in range(1,9): #megtalálta 1. ker: 199; 2. ker: 220; ...8. ker; 288.
    keruletimax=0 #kerületi max szavazat mindig 0-ról (vagy más kezdeti értékről) indul! FONTOS!!
    for i in szavazas:
        if kerulet==i[0]:
            if i[1]>keruletimax:
                keruletimax=i[1] #eddig megtalálta az 1. kerület max. szavazatát; 2. ker. max;...8. ker. max.
    #egy új for ismét végigmegy, hogy megtalálja: 1. kerület, max szavazatának sorát; 2. ker. max. sorát;...8. ker. max. sorát.
    for i in szavazas:
        if kerulet==i[0] and keruletimax==i[1]:
            if i[4]=='-':
                fki.write('%s %s %s függgetlen\n' %(i[0],i[2],i[3]))
                #print: képernyőre ír, parancs után új sorba megy a kurzor, nem kell: \n.
                #write, itt fki.write: fájlba ír, parancs után men megy új sorba a kurzor, kell: \n.
            else:
                fki.write('%s %s %s %s\n' %(i[0],i[2],i[3],i[4]))              
fki.close()


















    







        
