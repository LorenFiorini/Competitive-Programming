import random

f = open("test.txt", 'w')
def case():
	n = 1000
	m = 100 
	f.write(str(n) + " " + str(m) + "\n")

	for i in range(n) :
		for j in range(m):
			num = random.randint(1, 1000000000)
			f.write(str(num) + " ")
			
		f.write("\n")
		
f.write("10\n")
for _ in range(10):
	case()

f.close()
