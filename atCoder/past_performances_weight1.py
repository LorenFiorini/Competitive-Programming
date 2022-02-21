import random

def main():
	n = 10
	num = den = 0
	
	for i in range(1, n):
		perf = random.randint(800, 1000)
		num += (perf) * (0.9 ** i)
		den += 0.9 ** i
		ans = num / den
	
	for i in range(n):
		print(f"{i} : {perf}\t->\t{ans:.3f}")
		#print(f"{i} -> ( {1} * {num:.3f} ) / {den:.3f}")

main()
