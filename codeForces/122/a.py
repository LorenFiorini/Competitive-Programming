
def solve():
	n = int(input()) 
	if n % 7 == 0:
		print(n)
		return
	num = str(n)
	num = list(num)
	sz = len(num)
	
	if sz == 1:
		print(7)
	elif sz == 2:
		for i in range(10):
			s = num[0] + str(i)
			s = int(s)
			if s % 7 == 0:
				print(s)
				return
		for i in range(1, 10):
			s = str(i) + num[1]
			s = int(s)
			if s % 7 == 0:
				print(s)
				return
		print(14)
	else:
		for i in range(10):
			s = num[0] + num[1] + str(i)
			s = int(s)
			if s % 7 == 0:
				print(s)
				return
		for i in range(10):
			s = num[0] + str(i) + num[2]
			s = int(s)
			if s % 7 == 0:
				print(s)
				return
		for i in range(1, 10):
			s = str(i) + num[1] + num[2]
			s = int(s)
			if s % 7 == 0:
				print(s)
				return
		print(140)
		
t = int(input())

while t > 0:
	solve()
	t -= 1
