


def betterCompression(s):
	s = list(s)
	n = len(s)
	d = dict()
	alpha = "abcdefghijklmnopqrstuvwxyz"
	for c in alpha:
		d[c] = 0

	for i in range(n):
		if s[i].isalpha():
			num = 0
			j = i+1
			while j < n and s[j].isdigit():
				num *= 10
				num += int(s[j])
				j += 1
			d[s[i]] += num
	ans = ""
	for key in d:
		if d[key] > 0:
			ans += str(key) + str(d[key])
	return ans


print(betterCompression("a3c9b2c1"))
print(betterCompression("a12b56c1"))
print(betterCompression("a12c56a1b5"))

