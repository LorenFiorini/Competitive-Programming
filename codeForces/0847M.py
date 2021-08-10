n = int(input())
v = list(map(int, input().split()))

def solve():
	d = v[1] - v[0]
	for i in range(1, n):
		if v[i] - v[i-1] != d:
			print(v[n-1])
			return
	print(v[n-1] + d)
		
solve()
