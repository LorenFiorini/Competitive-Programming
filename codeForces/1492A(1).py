
def solve():
	p, a, b, c = map(int, input().split()) 
	
	if (p // a) * a == p or  (p // b) * b == p or  (p // c) * c == p:
		print(0)
		return
	
	ans = min( ((p//a)+1) * a, min( ((p//b)+1) * b, ((p//c)+1) * c))
	print(ans - p)
	

def main():
	t = int(input())
	for _ in range(1, t+1):
		solve()



if __name__ == "__main__":
    main()
