
n, p1, p2, p3, t1, t2 = map(int, input().split())

v = list()
for i in range(n):
	vec = list(map(int, input().split()))
	v.append(vec)

def get(time):
	ff = min(time, t1)
	time -= ff
	ss = min(time, t2)
	time -= ss
	return ff*p1 + ss*p2 + time*p3 

def solve():
	ans = 0
	last = v[0][0]
	for vec in v:
		ans += p1 * (vec[1] - vec[0])
		ans += get(vec[0] - last)
		last = vec[1]
	return ans

print(solve())
