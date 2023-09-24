s = list(input())


c4 = c7 = 0
for i in s:
	c4 += i == '4'
	c7 += i == '7'
	
if c4 + c7 == 0:
	print(-1)
elif c4 >= c7:
	print(4)
else:
	print(7)
