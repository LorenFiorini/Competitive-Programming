

def main():
	for a in range(999):
		for b in range(a+1, 1000):
			for c in range(b+1, 1001):
				if (a + b + c) == 1000 and pow(a, 2) + pow(b, 2) == pow(c, 2):
					print(a)
					print(b)
					print(c)
					print(a*b*c)
	
	
	return 0

if __name__ == '__main__':
	main()
