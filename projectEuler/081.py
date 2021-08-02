mx = 79
def dfs(mat, i, j, suma):
	suma += mat[i][j]
	if i == mx and j == mx:
		return suma
	right = down = 10000000000000
	if j+1 <= mx:
		right = dfs(mat, i, j+1, 0)
	if i+1 <= mx:
		down = dfs(mat, i+1, j, 0)
		
	suma += min(right, down)
	return suma

if __name__ == "__main__":
	f = open("081_matrix.txt", 'r')
	mat = list()
	for line in f:
		tmp = list(map(int, line.split(",")))
		mat.append(tmp)
	f.close()
	ans = dfs(mat, 0, 0, 0)
	
	print(ans)
