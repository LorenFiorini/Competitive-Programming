

def solve():
	n = int(input())
	a = list(map(int, input().split()))
	m = int(input())
	b = list(map(int, input().split()))
	
	for i in b:
		num = a[i-1]
		a.pop(i-1)
		a.append(num)
	print(a[0])
	
TT = int(input())
for _ in range(TT):
	solve()
