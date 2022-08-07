fi = open("text.txt", 'w')


N = 200000
sq = set( int(i*i) for i in range(N+1))

def f(n):
	ans = 0
	for j in range(1, n+1):
		for i in range(1, j+1):
			if i*j in sq: 
				ans += 1
		fi.write(str(ans) + ", ")

f(N)


fi.close()
