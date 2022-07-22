
'''

'''

def solve():
	n, x = map(int, input().split())
	#v = list()
	# one more and all up
	ans = 1e128
	pre = 0
	for i in range(n):
		a, b = map(int, input().split())
		pre += a + b
		x -= 1
		if x >= 0:
			ans = min(ans, pre + b * x)

		#v.append([a, b])

	# one more if its smaller than the smallest b
	# else all up to smallest b 
	#for i in range(n):


	print(ans)

solve()