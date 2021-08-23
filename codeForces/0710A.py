
p = list(input())
ans = 8

if p[0] == 'a' or p[0] == 'h':
	ans -= 3
	if p[1] == '1' or p[1] == '8':
		ans -= 2
elif p[1] == '1' or p[1] == '8':
	ans -= 3	

print(ans)
