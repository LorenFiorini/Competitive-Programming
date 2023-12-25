
"""Problem Statement
AtCoder Inc. sells merchandise on its online shop.

There are 
N items remaining in the company. The weight of the 
i-th item 
(1≤i≤N) is 
W 
i
​
 .

Takahashi will sell these items as 
D lucky bags.
He wants to minimize the variance of the total weights of the items in the lucky bags.
Here, the variance is defined as 
V= 
D
1
​
  
i=1
∑
D
​
 (x 
i
​
 − 
x
ˉ
 ) 
2
 , where 
x 
1
​
 ,x 
2
​
 ,…,x 
D
​
  are the total weights of the items in the lucky bags, and 
x
ˉ
 = 
D
1
​
 (x 
1
​
 +x 
2
​
 +⋯+x 
D
​
 ) is the average of 
x 
1
​
 ,x 
2
​
 ,…,x 
D
​
 .

Find the variance of the total weights of the items in the lucky bags when the items are divided to minimize this value.
It is acceptable to have empty lucky bags (in which case the total weight of the items in that bag is defined as 
0),
but each item must be in exactly one of the 
D lucky bags.

Constraints
2≤D≤N≤15
1≤W 
i
​
 ≤10 
8
 
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
D
W 
1
​
  
W 
2
​
  
… 
W 
N
​
 
Output
Print the variance of the total weights of the items in the lucky bags when the items are divided to minimize this value.
Your output will be considered correct if the absolute or relative error from the true value is at most 
10 
−6
 .

Sample Input 1
Copy
5 3
3 5 3 6 3
Sample Output 1
Copy
0.888888888888889
If you put the first and third items in the first lucky bag, the second and fifth items in the second lucky bag, and the fourth item in the third lucky bag, the total weight of the items in the bags are 
6, 
8, and 
6, respectively.

Then, the average weight is 
3
1
​
 (6+8+6)= 
3
20
​
 ,
and the variance is 
3
1
​
 {(6− 
3
20
​
 ) 
2
 +(8− 
3
20
​
 ) 
2
 +(6− 
3
20
​
 ) 
2
 }= 
9
8
​
 =0.888888…, which is the minimum.

Note that multiple items may have the same weight, and that each item must be in one of the lucky bags."""

















def solve():
	ans = 0
	N, D = map(int, input().split())
	W = list(map(int, input().split()))
	v = W[:]
	v.sort()
	print(v)
	print(ans)
	return



solve()

