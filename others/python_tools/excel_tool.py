
'''
def main():
	i = 0
	for line in cin:
		ls = list(line)
		if ls[0:2] == ['r', ' ']:
			ans = ''.join(ls[2:-1])
			cout.write(ans)
			#cout.write(' ')
			i += 1
			if i % 9 != 0:
				cout.write(', ')
			else:
				cout.write('\n')
		else:
			ans = ''.join(ls[:-1])
			cout.write(ans)
		
		#i += 1
		#if i % 7 != 0:
		#	cout.write(', ')
		#else:
		#	cout.write('\n')
	'''
def main():
	i = 0
	for line in cin:
		i += 1

		cout.write(line[:-1].capitalize())
		if i % 9 != 0:
			cout.write(', ')
		else:
			cout.write('\n')
	#cout.write(str(ans) + '\n')

if __name__ == "__main__":
	cin = open('inputf.in', 'r')
	cout = open('outputf.out', 'w')
	main()
	cin.close()
	cout.close()


# Lorenzo Fiorini
