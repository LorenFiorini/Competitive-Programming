

def solve():
    # n = int(input())
    v = [1]
    for i in range(4):
        v.append(v[-1] * 10 + 1)
    # pow_set()
    print(v)


solve()
