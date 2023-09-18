
def fib(n):
	v = ['0', '1']
	for i in range(2, n+1):
		s = v[i-1] + v[i-2]
		v.append(s)
	return v

def solve(n, s):
	mod = 1000000007
	s = list(s)
	
	ans = sum(1 for c in s if (c == '1'))
	p = pow(2, len(s) - 1, mod)
	ans = ((ans % mod) * p) % mod
	
	print(ans)
	return 

def main():
	t = int(input())
	mx = 0 
	nums = list()
	for _ in range(t):
		n = int(input())
		mx = max(mx, n)
		nums.append(n)
	f = fib(mx)
	for num in nums:
		solve(num, f[num])
	return

if __name__ == "__main__":
	main()

# Lorenzo Fiorini
