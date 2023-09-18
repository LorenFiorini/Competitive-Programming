import time
start = time.time()

for t in range(int(input())):
    n, a, b = [*map(int, input().split())]
    s = input()
    arr = [1]
    for i, e in zip([*range(1, n)], s[1:]):
        if s[i - 1] != e:
            arr.append(1)
        else:
            arr[-1] += 1
    res = 0
    if b > 0:
        res = (a + b) * sum(arr)
    else:
        dp = [[0 for _ in range(len(arr))] for __ in range(len(arr))]
        for i in range(len(arr)):
            dp[i][i] = a * arr[i] + b
        for i in range(1, len(arr)):
            for j in range(len(arr) - i):
                l = j
                r = j + i
                dp[l][r] = max(dp[l][r - 1] + arr[r] * a + b, dp[l + 1][r] + arr[l] * a + b)
                if (r - l + 1) % 2:
                    dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + (arr[l] + arr[r]) * a + b)
        res = dp[0][len(arr) - 1]
    print(res)

end = time.time()

print("Time: {} seconds".format(end - start))
