ans = 0
a, b, c = map(int, input().split())
if a>c:
	a,c = c,a
if (a+c) % 2:
	c += 1
	ans = 1
	
	
B = (a+c) / 2

if b <= B:
	ans += B - b
else:
	if ans:
		c -= 1
		a += 1
	ans += 2*b - (a + c)

print(int(ans))
