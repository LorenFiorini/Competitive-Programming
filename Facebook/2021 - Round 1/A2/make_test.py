
f = open("inputF.txt", 'w')
s = ['F', 'O', 'X']

n = 270000
f.write("1 \n" + str(n) + '\n')

for i in range(n):
	f.write("FOX")

f.write("\n")
f.close()
