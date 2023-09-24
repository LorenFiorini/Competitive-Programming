

def solve():
	s = input()
	n = len(s)
	ans = 0

	for i in range(1, n):
		suma = int(s[i-1]) + int(s[i])
		num = s[0:i-1] + str(suma) + s[i+1:]
		ans = max(ans, int(num))
		#print(num, end="-")

	print(ans)


t = int(input())
while t > 0:
	solve()
	t -= 1
