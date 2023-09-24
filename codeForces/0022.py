n = int(input())
v = list(map(int, input().split()))
v.sort()

ans = "NO"
for i in range(1,n):
	if v[i] != v[i-1]:
		ans = v[i]
		break
print(ans)
