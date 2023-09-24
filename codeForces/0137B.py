n = int(input())
v = map(int, input().split())

ans = 0
st = set()
for num in v:
	if num > n:
		ans += 1
	elif num in st:
		ans += 1
	else:
		st.add(num)

print(ans)
