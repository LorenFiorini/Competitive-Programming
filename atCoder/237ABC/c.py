
def palin(s):
	n = len(s)
	for i in range(n):
		if s[i] != s[n-i-1]:
			return 0
	return 1

def solve(s):
	s = list(s)
	end = 0
	beg = 0
	while len(s) > 0 and s[-1] == 'a':
		s.pop()
		end += 1
	
	for i in range(len(s)):
		if s[i] != 'a':
			beg = i
			break
	
	if (end >= beg):
		return palin(s[beg:])
	return 0 == len(s)
	
	
s = input()

if solve(s):
	print("Yes")
else:
	print("No")
