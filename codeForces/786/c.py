
def dfs(s, t):
	tmp = "".join(s)
	st.add(tmp)
	for i in range(len(s)):
		if s[i] == 'a':
			tmp = s[0:i] + t + s[i+1:]
			dfs(tmp, t)
	

s = list("aaaaa")
t = list("bcc")
st = set()

dfs(s, t)

for i, a in enumerate(st):
	print(i, a)
