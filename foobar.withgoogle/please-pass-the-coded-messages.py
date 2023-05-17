def solution(l):
    digits = [0 for i in range(10)]
    for num in l:
        digits[num] += 1
    for i in range(10):
        digits[i] = int(min(digits[i], 9))
    def dfs(digits, p, cnt, num):
        if p < 0 or cnt > 9:
            if num % 3 == 0:
                return num
            return 0
        ans = 0
        if num % 3 == 0:
            ans = num
        if digits[p] > 0:
            digits[p] -= 1
            ans = max(ans, dfs(digits, p, cnt + 1, num * 10 + p))
            digits[p] += 1
        ans = max(ans, dfs(digits, p - 1, cnt, num))
        #print(ans, end=", ")
        return ans
    return dfs(digits, 9, 0, 0)

print(solution([3, 1, 4, 1]))
print(solution([3, 1, 4, 1, 5, 9]))
print(solution([9, 9, 9, 9, 9, 9, 9, 9, 9, 9]))

