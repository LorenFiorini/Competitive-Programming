import sys

tc = int(sys.stdin.readline().strip())

for i in range(tc):
    n = int(sys.stdin.readline().strip())
    x = list(map(int, sys.stdin.readline().strip().split(" ")))

    a = x[0]
    ret = 0
    for b in x[1:]:
        if a < b:
            a = b
            continue
        mult = 1
        while True:
            mult *= 10
            ret += 1
            if a < ((b + 1) * mult) - 1:
                if a < b * mult:
                    a = b * mult
                else:
                    a = b * mult + (a % mult) + 1
                break
    print(f"Case #{i + 1}: {ret}")
