#halmaz =set: olyan tömb, nincsenek ismétlődő elemek
#halmazban nincs az elemeknek sorrendje
nap=set() #üres halmaz inicializálása
nap={'hétfő','kedd','szerda','csütörtök','péntek'}
#ha a halmazt elemeinek felsorolásával adjuk meg, akkor: {.,.,.,.,.}
print(nap)
if 'szombat' in nap:
    print('igen')
else:
    print('nem')

if 'vasárnap' not in nap:
    print('igen')
else:
    print('nem')
#in, not in: listákra is működik
#halmaz (set) feltöltése: append helyett add
nap.add('szombat')
print(nap)
#halmaz elemének eltávolítása: -
nap=nap-{'szombat'}
print(nap)

#hasznos a set, ha egy lista egyedi elemei szükségesek:
A=[3,3,3,3,3,4,4,4,4,4,1,1,2,2,5,5,5]
Aset=set(A)
print(Aset)

A=list(Aset) #visszaalakítottuk a halmazt listára
