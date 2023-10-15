
import math

def main():
	x = float(input("Enter a number: "))
	while (x > 1):
		x = 2 * x / (1 + math.sqrt(5))
		print(f'{x:.1f}\t->\t{hex(int(x))}')
	return


if __name__ == '__main__':
	main()
