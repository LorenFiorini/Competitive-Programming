
def read():
	f = open("5-letter-words.txt", 'r')
	v = []
	i = 0
	for line in f:
		v.append(list(line))
	return v
	
def main():
	v = read()
	s = list(input("5 letter dash (-) for unknown:"))
	t = list(input("5 letter dash (-) for unknown:"))
	con = list(input("Contain: "))
	no = list(input("Do not contain: "))
	
	for a in v:
		ok = 1
		for i in range(5):
			ok &= (s[i] == '-' or a[i] == s[i])
			ok &= (a[i] != t[i])
			
		st = set(a)
		for let in con:
			ok &= (let in st)
		for let in no:
			ok &= not(let in st)
		
		if ok:
			q = "".join(a)
			print(q)
		
main()
