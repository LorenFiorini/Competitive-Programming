

def main():
	f = open("5LetterWords.txt", 'r')
	v = list()
	for line in f:
		v.append(str(line))
	
	ins = list("ae")
	out = list("nivlrgc")
	#print(s)
	for word in v:
		W = list(word)
		if W[1] != 'a' or W[2] != 'u'or W[3] != 's'or W[4] != 'e':	
			continue
		
		w = set(word)
		ok = True
		for c in ins:
			ok &= c in w
		for c in out:
			ok &= not (c in w)
		
		if ok:
			print(word)
			
main()
