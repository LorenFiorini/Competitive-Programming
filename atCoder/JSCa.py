import math

def main():
	x, y, z = input().split()
	x = int(x)
	y = int(y)
	z = int(z)
	a = y * z / x
	if a - math.floor(a) == 0:
		a -= 1
	
	a = int(a)
	print(a)
	
	return 0

if __name__ == '__main__':
	main()
