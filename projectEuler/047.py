from sympy.ntheory import factorint

ok = False
four = set()
i = 0
a = list()
while not ok:
	i += 1
	a = list(factorint(i))
	"""print("Numbers : {}, {} and {}".format(i, i+1, i+2))
	print(a)
	print(b)
	print(c)"""
	if len(a) == 4:
		four.add(i)
		ok = (i-1 in four) and (i-2 in four) and (i-3 in four)

print(i-3)
