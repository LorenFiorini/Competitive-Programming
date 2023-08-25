import random
import numpy as np

import os
import subprocess

from datetime import datetime

def generate_case(input_file, n=10, m=10):
	A = np.random.uniform(0, 1, (n, m))
	# A = A > np.random.uniform(0.4, 1.0)
	A = A > np.random.normal(0.7, 0.2)

	ifile = open(input_file, "w")
	for i in range(n):
		for j in range(m):
			if A[i][j]:
				ifile.write("o")
			else:
				ifile.write(".")
		ifile.write("\n")
	ifile.close()

def execute_case(input_file, program):
	start = datetime.now()
	output = subprocess.Popen([program, input_file]).wait()
	end = datetime.now()
	print (f"{input_file}: \n\t{output}: {(end - start).total_seconds()} s\n")


def main(args=None):
	dir = '.'
	pattern = 'test_'

	names = set([f for f in os.listdir(dir) if pattern in f])

	#for _ in range(1):
		# n, m = random.choice(range(1, 30000)), random.choice(range(1, 30000))
		# size = np.random.lognormal(0, 1, (1, 2)) * 5000
		# size = np.min(np.append(size, [[16000, 16000]], axis=0), axis=0)
		# size = np.round(size).astype(int)
		# size = [33000, 33000]
		
		# j = 0
		# name = f"test_{size[0]:05d}_{size[1]:05d}_{j}.txt" 
		# while name in names:
		# 	j += 1
		# 	name = f"test_{size[0]:05d}_{size[1]:05d}_{j}.txt"
		# names.add(name)
		# generate_case(name, size[0], size[1])
	
	for f in os.listdir(dir):
		if pattern in f:
			execute_case(f, "../bsq")

main()
