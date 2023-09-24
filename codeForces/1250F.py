
n = int(input())
a = 1
b = n

div = set()
for i in range(1, n//2+1):
	if n % i == 0:
		if i in div or i == n//i:
			a = i
			b = n//i
			break
		div.add(i)
		div.add(n//i)

print(2 * (a+b))
