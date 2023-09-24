
def mk():
	V = list()
	for i in range(10):
		V.append(0)
	return V

def main():
	mod = 998244353;
	n = int(input())
	v = list(map(int, input().split()))
	
	ans = mk()
	ans[v[0]] = 1
	
	for k in range(1, n):
		nxt = mk()
		for i in range(10):
			nxt[(i + v[k]) % 10] += (ans[i] % mod)
			nxt[(i * v[k]) % 10] += (ans[i] % mod)
		ans = nxt
	
	for i in ans:
		print(i % mod)


if __name__ == "__main__":
	main()

# Lorenzo Fiorini
