
"""
You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.

An index i is good if the following formula holds:

0 <= i < variables.length
(( (a[i] ^ b[i]) % 10) ^ c[i]) % m[i] == target
Return an array consisting of good indices in any order.

"""

# class Solution:
# 	def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
# 		ans = [1 for i in range(len(variables)) if (((variables[i][0] ^ variables[i][1]) % 10) ^ variables[i][2]) % variables[i][3] == target]
# 		return ans

from typing import List
import math

class Solution:
	def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
		ans = []
		for i in range(len(variables)):
			# print("((variables[i][0] ^ variables[i][1]) % 10) = " + str((variables[i][0] ^ variables[i][1]) % 10))
			# print("((variables[i][0] ^ variables[i][1]) % 10) ^ variables[i][2] = " + str(((variables[i][0] ^ variables[i][1]) % 10) ^ variables[i][2]))
			# print("(((variables[i][0] ^ variables[i][1]) % 10) ^ variables[i][2]) % variables[i][3] = " + str((((variables[i][0] ^ variables[i][1]) % 10) ^ variables[i][2]) % variables[i][3]))
			print("----------------")
			print("variables = " + str(variables[i]))
			print((variables[i][0] ^ variables[i][1]) % 10)
			print((variables[i][0] ^ variables[i][1]) % 10 ^ variables[i][2])
			print(((variables[i][0] ^ variables[i][1]) % 10 ^ variables[i][2]) % variables[i][3])
			if (int(int(variables[i][0] ** variables[i][1]) % 10) ** variables[i][2]) % variables[i][3] == target:
				ans.append(i)
		return ans



#test
sol = Solution()
variables = [
	[[2,3,3,10],[3,3,3,1],[6,1,1,4]],
	[[39,3,1000,1000]],
	[[2,2,3,2],[1,3,3,2],[3,2,2,3],[3,1,2,3],[1,2,3,1],[2,2,2,2],[2,1,3,1],[3,2,2,2],[2,1,3,1],[3,3,1,3]]
]
targets = [
	2,
	17,
	0
]
expected = [
	[0,2],
	[],
	[0,2,3,4,5,6,8]
]

for i in range(len(variables)):
	print("Test case " + str(i+1))
	ans = sol.getGoodIndices(variables[i], targets[i])
	print("Output: " + str(ans))
	print("Expected: " + str(expected[i]))
	print("Passed: " + str(ans == expected[i]))
	print()
