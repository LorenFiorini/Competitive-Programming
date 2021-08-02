

if __name__ == "__main__":
	f = open("081_matrix.txt", 'r')
	v = list()
	for line in f:
		tmp = list(map(int, line.split(",")))
		v.append(tmp)
	f.close()
	n = len(v)
	for i in range(n):
		for j in range(n):
			if i == 0 == j:
				continue
			elif i == 0:
				v[i][j] += v[i][j-1]
			elif j == 0:
				v[i][j] += v[i-1][j]
			else:
				v[i][j] += min(v[i][j-1], v[i-1][j])
			
	
	print(v[n-1][n-1])
