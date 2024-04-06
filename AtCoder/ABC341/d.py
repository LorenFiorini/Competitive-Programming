import math

N, M, K = map(int, input().split())

def main(n, m, k):
    # print(n, m, k)
    g = math.gcd(n, m)
    L = math.lcm(n, m)
    # print("gcd:", g, " - lcm:", L)
    C = (n - 1) + (m - 1)
    # print("C", C)
    ans = L * (k // C) - 1
    print("ans", ans)
    k = k % C
    # print(k)
    if k == m:
        print(ans)
        return
    while k > n-1:
        # tmp = min(k, k // m)
        tmp = min(k, n - 1)
        k -= tmp
        ans += tmp * m
    print(ans)
    while k > 0:
        tmp = min(k, m - 1)
        k -= tmp
        ans += tmp * n
        # if k == 0:
        #     break
        # k -= 1
        # ans += 1 * m
    print(ans)

main(min(N, M), max(N, M), K)
