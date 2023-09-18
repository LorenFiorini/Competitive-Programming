n = int(input())
v = list(map(int, input().split()))
ans = 0
odd = sum(i for i in v) % 2

for i in v:
	if (i&1) == odd:
		ans += 1

print(ans)
