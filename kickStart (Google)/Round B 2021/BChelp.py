

f = open('prime.txt', 'r')
f2 = open('out.txt', 'w')

cnt = 0
for row in f:
	line = list(map(str, row.split()))
	
	for num in line:
		f2.write(num)
		f2.write(", ")
		cnt +=1

f2.write("\n")
f2.write(str(cnt))
