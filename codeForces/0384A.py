ans = 0
n = int(input())
v = [ ['.'] * n for i in range(n)]

for i in range(n):
	for j in range(n):
		if (i+j) % 2 == 0:
			v[i][j] = "C"
			ans += 1

print(ans)
for i in v:
	s = "".join(i)
	print(s)

''''
1
13
1000000000
2784381467700
496811800468306
350551360251708
297443489238309
''''
