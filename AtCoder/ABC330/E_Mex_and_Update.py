

def mex(A):
    mex = 0
    while mex in A:
        mex += 1
    return mex

def solve():
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    for _ in range(Q):
        i, x = map(int, input().split())
        A[i] = x
        print(mex(A))

solve()
