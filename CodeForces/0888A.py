n = int(input())
v = list(map(int, input().split()))

ans = 0
for i in range(1, n-1):
	ans += (v[i-1] < v[i] > v[i+1]) or (v[i-1] > v[i] < v[i+1]) 

print(ans)
