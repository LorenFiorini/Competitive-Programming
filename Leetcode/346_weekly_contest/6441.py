
def check(num, sm, t):
	# Debug	if (t == 81):	print(num, sm, t)
	if num == 0:
		if sm == t:
			return True
		else:
			return False
	if sm > t:
		return False
	k = 10
	while k <= num:
		if check(num // k, sm + (num % k), t):
			return True
		k *= 10
	return check(num // k, sm + (num % k), t)


def main():
	n = int(input())
	ans = 0
	for num in range(1, 11):
		t = num * num
		if check(t, 0, num):
			#print(num)
			ans += t
			#print(ans, t)
		#print(t)
	return ans
main()
