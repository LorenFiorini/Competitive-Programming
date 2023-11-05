import random
import numpy as np

from datetime import datetime

ELEMENT = ["W", "A", "E"]

def generate_case(input_file, n=10, m=10):
	terrain = np.random.randint(3, size=(n, m))
	cost = np.random.randint(10, size=(n, m))

	start = np.random.randint([0, 0], [n, m])
	goal = np.random.randint([0, 0], [n, m])
	while np.all(start == goal):
		goal = np.random.randint([0, 0], [n, m])

	ifile = open(input_file, "w")
	for i in range(n):
		for j in range(m):
			if np.all(start == [i, j]):
				ifile.write("MM")
			elif np.all(goal == [i, j]):
				ifile.write("GG")
			else:
				ifile.write(f"{ELEMENT[terrain[i, j]]}{cost[i, j]}")
		ifile.write("\n")
	ifile.close()

def main():
	names = set()
	for i in range(5):
		# n, m = random.choice(range(1, 1000)), random.choice(range(1, 1000))
		n, m = 5,5
		j = 0
		name = f"test_{n:05d}_{m:05d}_{j}"
		while name in names:
			j += 1
			name = f"test_{n:05d}_{m:05d}_{j}"
		names.add(name)
		generate_case(name + ".txt", n, m)

if __name__ == "__main__":
	main()