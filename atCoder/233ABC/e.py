

x = input()
n = len(x)
x = int(x)

ans = 0

while x > 0:
	ans += x
	x //= 10
	

print(ans)
