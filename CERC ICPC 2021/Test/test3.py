
n = int(input())
v = [0] * n
for i in range(n):
	v[i] = int(input()) 
print(n)
for i in range(n):
	print(v[-i-1]) 
