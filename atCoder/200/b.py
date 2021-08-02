
def solve():
	n, k = input().split()
	n = int(n)
	k = int(k)
	
	for i in range(k):
		if n % 200 == 0:
			n /= 200
		else:
			n *= 1000
			n += 200
	
	print(int(n))
	

def main():
	solve()
	

if __name__ == "__main__":
    main()
