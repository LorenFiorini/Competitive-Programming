n = int(input())
v = list(map(int, input().split()))

o = e = 0

for num in v:
	o += num & 1
	e += not(num & 1)
	
for i in range(n):
	if e == 1 and v[i]%2 == 0:
		print(i+1)
		break
	if o == 1 and v[i]%2 == 1:
		print(i+1)
		break
