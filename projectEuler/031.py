

ans = 0
coins = [200, 100, 50, 20, 10, 5, 2, 1]

def dfs(suma, pos):
	global ans
	if suma > 200:
		return
	if suma == 200:
		ans += 1
		return
	for i in range(pos, len(coins)):
		dfs(suma + coins[i], i)

for i in range(len(coins)):
	dfs(coins[i], i)

print(ans)
"""
coins = [1, 2, 5, 10, 20, 50, 100, 200]
#coins.reverse()

dp = [0] * 201
dp[0] = 0
dp[1] = 1
for i in range(2, 202):
	for c in coins:
		if c > i:
			break
		dp[i] += dp[i-c]

for c in range(200):
	print(200 - c, " ", dp[c])
"""
