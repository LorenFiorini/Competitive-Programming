class Solution:
	def punishmentNumber(self, n: int) -> int:
		def check(num, sm, t):
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
		ans = 0
		for num in range(1, n+1):
			t = num * num
			if check(t, 0, num):
				ans += t
				print(ans, num)
		return ans
