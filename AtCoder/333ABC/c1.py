mx = 18
nums = [1] * mx
st = set()

def dfs(p, c, num):
	if c == 0:
		st.add(num)
		return
	for i in range(p, mx):
		dfs(i, c - 1, num + nums[i])


for i in range(1, mx):
	nums[i] *= 10 + 1
dfs(0, 3, 0)
A = st
n = int(input())

