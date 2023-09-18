
def lucky(n):
	cnt = 0
	while n > 0:
		d = n % 10
		if d == 4 or d == 7:
			cnt += 1
		n = n // 10
		
	if cnt==0:
		print("NO")
		return
		
	while cnt > 0:
		d = cnt % 10
		if d != 4 and d != 7:
			print("NO")
			return
		cnt = cnt // 10
	print("YES")

n = int(input())
lucky(n)
