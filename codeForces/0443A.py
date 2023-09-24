


a = input()
a = a[1:-1]
st = set(a.split(", "))

if len(st) == 1:
	if "" in st:
		print(0)
	else:
		print(1)
else:	
	print(len(st))
