import math

ans = 0
num = math.factorial(100)
while num > 0:
	ans += num % 10
	num //= 10

print(ans)
