
'''Problem Statement
You are given a positive integer 
D.

Find the minimum value of 
∣x 
2
 +y 
2
 −D∣ for non-negative integers 
x and 
y.

Constraints
1≤D≤2×10 
12
 
All input values are integers.
'''


# import math

# def dfs(D, cnt):
#     if cnt == 0:
#         return abs(D)
#     num = int(math.sqrt(D))
#     a = num * num
#     b = (num + 1) * (num + 1)
#     ans = min(dfs(D - a, cnt - 1), dfs(D - b, cnt - 1))
#     return min(ans, abs(D))
    

# def solve():
#     D = int(input())
#     ans = dfs(D, int(2))
#     return ans

# print(solve())

import math

def solve():
    D = int(input())
    ans = D
    x = int(math.sqrt(D)) + 3
    y = 0
    while x >= y:
        x -= 1
        if x * x < D:
            y = int(math.sqrt(D - x * x))
        suma = x * x + y * y
        ans = min(ans, abs(suma - D))
        if suma < D:
            y += 1
            suma = x * x + y * y
            ans = min(ans, abs(suma - D))
    print(ans)

solve()
