def solution(n, b):
    ans = 0
    l = list(n)
    k = len(n)
    x = sorted(l)
    y = sorted(l, reverse = 1)
    print(x, y)

    return ans

print(solution('1211', 10))
print(solution('210022', 3))
