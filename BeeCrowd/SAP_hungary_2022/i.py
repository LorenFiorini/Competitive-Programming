


n = int(input())
h,c,l = map(float, input().split())
l /= 100
c = c*n / 100
h = h*n / 100

#ans = l * pow(pow(n*c, 2) + pow(n*h, 2), 0.5)

ans = l * pow(c ** 2 + h ** 2, 0.5)

print("{:.4f}".format(round(ans, 4)), flush=True)
