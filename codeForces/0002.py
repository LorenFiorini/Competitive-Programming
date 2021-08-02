
n = int(input())
mp = dict()

v = []
for i in range(n):
	a, b = map(str, input().split())
	b = int(b)
	if a not in mp:
		mp[a] = b
	else: 
		mp[a] += b
		
	tmp = list()
	tmp.append(a)
	tmp.append(b)
	v.append(tmp)

mx = max(mp[name] for name in mp)
cnt = sum(1 for name in mp if mp[name] == mx)

ans = str()
if cnt == 1:
	for name in mp:
		if mp[name] == mx:
			ans = name
			break	
else:
	for name in mp:
		mp[name] = 0
	for i in range(n):
		mp[v[i][0]] += v[i][1]
		if mp[v[i][0]] == mx:
			ans = v[i][0]
			break
	
print(ans)

