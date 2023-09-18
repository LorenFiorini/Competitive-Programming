ans = "YES"
v = []

for i in range(3):
	s = list(input())
	v.append(s);
	
for i in range(3):
	for j in range(3):
		if v[i][j] != v[2-i][2-j]:
		ans = "NO"

print(ans)
