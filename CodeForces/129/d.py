

def get(num):
	ans = set()
	while num > 0:
		if num % 10 > 1:
			ans.add(num % 10)
		num //= 10
	ls = list(ans)
	ls.sort(reverse = True) 
	return ls

def dfs(n, num, cnt):
	sz = len(str(num))
	if sz == n:
		return cnt
	elif sz > n:
		return int(1e9)
	
	ans = int(1e9)
	ls = get(num)
	for val in ls:
		res = dfs(n, num * val, cnt+1)
		if res < ans:
			ans = res
		
	return ans

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


