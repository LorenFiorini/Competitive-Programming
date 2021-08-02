
d = 0
num = ""
while len(num) <= (10 ** 6):
	num += str(d)
	d += 1

ans = 1
for i in range(7):
	a = int(num[10 ** i])
	print(i, " ", a)
	ans *= a
	
print(ans)
