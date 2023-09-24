

def solve():
	a, b = map(int, input().split())
	
	if a%b == 0:
		print(0)
	else:
		ans = b * ((a//b)+1) - a
		print(ans)

t = int(input())
for case in range(t):
	solve() 
