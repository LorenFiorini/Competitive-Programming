
def solve():
	n = int(input())
	s = input()
	
	v = list()
	
	for i in range(n//2 + 1):
		for j in range(i + n//2, n+1):
			num = int(s[i : j], 2)
			for pre in v:
				if (pre[0] % num) == 0:
					print(f"{pre[1] + 1} {pre[2]} {i + 1} {j} ")
					return
				elif (num % pre[0]) == 0:
					print(f"{i + 1} {j} {pre[1] + 1} {pre[2]}")
					return
			
			tmp = [num, i, j]
			v.append(tmp)

T = int(input())
for _ in range(T):
	solve()
