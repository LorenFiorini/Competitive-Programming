

def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    for _ in range(q):
        op, *args = input().split()
        if op == '1':
            s = int(args[0])
            if s == 0:
                print('YES')
                continue

            prefix_sums = [0]
            for i in range(1, n + 1):
                prefix_sums.append(prefix_sums[-1] + a[i - 1])

            start, end = 0, n
            while start < end:
                mid = (start + end) // 2
                if prefix_sums[mid + 1] - prefix_sums[mid] == s:
                    print('YES')
                    break
                elif prefix_sums[mid + 1] - prefix_sums[mid] > s:
                    end = mid
                else:
                    start = mid + 1
            else:
                print('NO')

        elif op == '2':
            i, v = int(args[0]), int(args[1])
            a[i - 1] = v



def main():
	t = int(input())
	for _ in range(t):
		solve()

if __name__ == "__main__":
	main()
