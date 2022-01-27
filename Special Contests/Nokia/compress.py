
s = str(input())
s = list(s)
ans = ""
cnt = 0
lst = s[0]
for dig in s:
	if dig == lst:
		cnt += 1
	else:
		ans += '(' + str(cnt) + "," + lst + ')'
		cnt = 1
		lst = dig
	

ans += '(' + str(cnt) + "," + lst + ')'
print(ans)
