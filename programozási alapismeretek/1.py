print('Hello World!')
# print: képernyőre ír
a=int(input('Kérem az első számot: a='))
# input: adat bekérése billentyűzetről (szöveg btípus érkezik billentyűzetről)
# int: egész számmá alakít
b=int(input('Kérem a második számot: b='))
#matematikai műveletek:
print('összeg: ',a,'+',b,'=',a+b)
print('különbség: ',a,'-',b,'=',a-b)
print('szorzat: ',a,'*',b,'=',a*b)
print('hányados: ',a,'/',b,'=',a/b)
print('osztási maradék: ',a,'mod',b,'=',a%b) #pl: 7/5=1, maradék=2.
print('osztási egész: ',a,'div',b,'=',a//b) #pl: osztási egész=1.
print('hatvány: ',a,'^',b,'=',a**b)

#elágazás: IF (ELIF, ELIF, ...., ELSE)
#szám paritásának vizsgálata ("a" páros vagy páratlan)
if a%2==0: #==: megegyezik, !=:nem egyezik meg, nem egyenlő, eltérő, különböző
    print(a,'páros szám')
else:
    print(a,'páratlan szám')
#Jó munkalehetőség: szoftvertesztelés (nagyon keresett)
#Jó munkalehetőség: mesterséges intelligencia (nagyon keresett)

#faktoriális: 8!=1*2*3*4*5*6*7*8.
#iteráció=bejárós ciklus=FOR ciklus
fakt=1 #inicializálás=kezdeti érték megadása
for i in range(1,a+1): #1, 2, 3, 4, 5, 6, 7, 8=a+1.
    #                   Tehát a range tartomány utolsó értékét a for nem végzi el.
    fakt*=i #fakt=fakt*i
print(a,'!=',fakt) #!: felkiáltójel.

#p szám prím vagy nem prím?  pl: 144,149.
p=int(input('p='))
vanoszto=False #logikai változó, boolean
for i in range(2,p//2+1):
    if p%i==0:
        vanoszto=True
if vanoszto==False:
    print('%s prím szám' %(p)) #%: százalékjel, ':aposztróf (shift+1), ":idézőjel (shift+2).
else:
    print('%s nem prím szám' %(p))

#tökéletes szám= a számnál kisebb osztók összege megegyezik a számmal (6, 28, 496, ...)
# 28=1+2+4+7+14.
osztoszum=0
for i in range(1,p):
    if p%i==0:
        osztoszum+=i #osztoszum=osztoszum+i
if osztoszum==p:
    print('%s tökéletes szám' %(p))
else:
    print('%s nem tökéletes szám' %(p))
    
#lnko= legnagyobb közös osztó
'''
24, 25: lnko=1
25, 100: lnko=25
25, 95: lnko=5
'''
x=int(input('x='))
y=int(input('y='))
lnko=1
if x<y:
    kisebb=x
else:
    kisebb=y
for i in range(1,kisebb+1):
    if x%i==0 and y%i==0:
        lnko=i
print('%s és %s: lnko=%s' %(x,y,lnko))

#lkkt= legkisebb közös többszörös
'''
24, 25: lkkt=600
25, 100: lkkt=100
25, 95: lkkt=475
'''
lkkt=x*y
if x<y:
    nagyobb=y
else:
    nagyobb=x
for i in range(x*y,nagyobb-1,-1): #lépésköz=step=-1; range(start,stop,step)
    if i%x==0 and i%y==0:
        lkkt=i
print('%s és %s: lkkt=%s' %(x,y,lkkt))













        
