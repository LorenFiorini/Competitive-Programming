

def solve():
	n, k = input().split()
	n = int(n)
	k = int(k)
	s = str(input())
	score = 0
	for i in range(n // 2):
		if s[i] != s[n-1-i]:
			score += 1
	
	return abs(score - k)


def main():
	t = int(input())
	for _ in range(1, t + 1):
		ans = int(solve())
		print("Case #{}: {}".format(_, ans))
	




if __name__ == '__main__':
	main()


"""

2
5 1
ABCAA
4 2
ABAA

"""
