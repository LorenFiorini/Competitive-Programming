

ans = 0
for num in range(1, 1001):
	ans += num ** num
	ans %= 10 ** 10

print(ans)
