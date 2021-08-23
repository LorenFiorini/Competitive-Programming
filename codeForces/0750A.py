ans = 0
n, k = map(int, input().split())

time = 240 - k

while time-(ans+1) * 5 >= 0:
	ans += 1
	time -= ans * 5
	
print(min(n, ans))
