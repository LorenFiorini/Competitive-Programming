

def get(num):
	ans = set()
	while num > 0:
		if num % 10 > 1:
			ans.add(num % 10)
		num //= 10
	ls = list(ans)
	ls.sort(reverse = True) 
	return ls

def bfs(n, num):
	q = []
	
	while len(q)

def solve():
	n, x = map(int, input().split())
	if x == 1 or len(str(x)) > n:
		print(-1)
	ans = dfs(n, x, 0) 
	if ans < int(1e9):
		print(ans)
	else :
		print(-1)

solve()


