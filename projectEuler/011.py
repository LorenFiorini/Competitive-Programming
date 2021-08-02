
def check(i, j):
	num = 1
	for d in range(4):
		#if i + d < 20 and j + d < 20:
		num *= v[(i + d) % 20][(j + d) % 20]
	return num



v = list()
for i in range(20):
	row = list(map(int, input().split()))
	v.append(row)

ans = 0
for r in range(2):
	for i in range(17):
		for j in range(17):
			ans = max(ans, check(i, j))
			#print(v[i][j], end="\t")
	for i in range(20):
		v[i].reverse()
		
	
print(ans)
