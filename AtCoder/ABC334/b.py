

a, m, l, r = map(int, input().split())

l -= a
r -= a
le = l // m
if l % m != 0:
	le += 1
ri = r // m
ans = ri - le + 1
print(ans)
