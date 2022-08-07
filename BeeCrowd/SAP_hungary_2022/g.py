

n = int(input())
v = [0 for i in range(n)]
for i in range(n):
	v[i] = int(input())

mx = max(v)	
if n > 1:
	ans = sum(v) - mx + 1
else:
	ans = mx+1
print(ans)
