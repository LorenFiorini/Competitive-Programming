# Problem 6442: Modify Graph Edge Weights

'''
You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [a_i, b_i, w_i] indicates that there is an edge between nodes a_i and b_i with weight w_i.

Some edges have a weight of -1 (w_i = -1), while others have a positive weight (w_i > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 10^9] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.
'''

class Solution:
	def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
		



def main():
	a = Solution()
	for _ in range(3):
		n = int(input())
		edges = list(map(int, input().split()))
		source = int(input())
		destination = int(input())
		target = int(input())
		print(a.modifiedGraphEdges(n, edges, source, destination, target))
	return 0

main()

'''
Input:
5
[[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]]
0
1
5
3
[[0,1,-1],[0,2,5]]
0
2
6
4
[[1,0,4],[1,2,3],[2,3,5],[0,3,-1]]
0
2
6

Output:
[[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
[]
[[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
'''
