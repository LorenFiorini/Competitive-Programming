def rem(num):
	num = list(str(num))
	ans = [c for c in num if c != '0']
	ans = "".join(ans)
	return int(ans)


a = int(input())
b = int(input())
c = rem(a + b)

A = rem(a)
B = rem(b)
C = A + B

if C == c:
	print("YES")
else:
	print("NO")
