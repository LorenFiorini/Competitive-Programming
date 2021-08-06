ax, ay, bx, by = map(int, input().split())
x, y = map(int, input().split())

if abs(ax-bx) % x == 0 == abs(ay-by) % y and (abs(ax-bx)/x) % 2 == (abs(ay-by)/y) % 2:
	print("YES")
else:
	print("NO")
