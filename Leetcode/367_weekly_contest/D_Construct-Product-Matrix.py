
"""
Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:

Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid
"""

# class Solution:
# 	def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
# 		mod = 12345
# 		n = len(grid)
# 		m = len(grid[0])
# 		ans = [[0 for i in range(m)] for j in range(n)]
# 		total_mult = 1
# 		count_zero = 0
# 		for i in range(n):
# 			for j in range(m):
# 				if grid[i][j] == 0:
# 					count_zero += 1 
# 				else:
# 					total_mult = (total_mult * grid[i][j]) % mod
# 				if count_zero > 1:
# 					return ans
# 		return ans

class Solution:
	def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
		mod = 12345
		n = len(grid)
		m = len(grid[0])
		if n == 1 and m == 1:
			return [grid[0][0]]
		ans = [[0 for i in range(m)] for j in range(n)]
		total_mult = 1
		count_zero = 0
		where_zero = []
		for i in range(n):
			for j in range(m):
				if grid[i][j] == 0:
					count_zero += 1
					where_zero = [i, j]
				else:
					total_mult = (total_mult * grid[i][j]) % mod
					grid[i][j] %= mod
				if count_zero > 1:
					return ans
		if count_zero > 0:
			ans[where_zero[0]][where_zero[1]] = total_mult
			return ans
		for i in range(n):
			for j in range(m):
				if grid[i][j] != 0:
					ans[i][j] = (total_mult // grid[i][j]) % mod
				else:
					ans[i][j] = total_mult
		return ans
	

class Solution:
	def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
		mod = 12345
		n = len(grid)
		m = len(grid[0])
		if n == 1 and m == 1:
			return [grid[0][0]]
		ans = [[0 for i in range(m)] for j in range(n)]
		total_mult = 1
		count_zero = 0
		where_zero = []
		for i in range(n):
			for j in range(m):
				if grid[i][j] == 0:
					count_zero += 1
					where_zero = [i, j]
				else:
					total_mult = (total_mult * grid[i][j]) % mod
					grid[i][j] = grid[i][j] % mod
					if total_mult == 0:
						total_mult += mod
				if count_zero > 1:
					return ans
		if count_zero > 0:
			ans[where_zero[0]][where_zero[1]] = total_mult
			return ans
		for i in range(n):
			for j in range(m):
				if grid[i][j] != 0:
					ans[i][j] = int((10 * mod + total_mult) / grid[i][j]) % mod
				else:
					ans[i][j] = total_mult
		return ans