v = list(map(int, input().split()))

stairs = v[3] * abs(v[1] - v[0])
elevator = (abs(v[2] - v[0]) + abs(v[0] - v[1])) * v[4] + 3 * v[5]

if elevator <= stairs:
	print("YES")
else:
	print("NO") 
