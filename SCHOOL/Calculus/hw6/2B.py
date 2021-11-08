import math
import matplotlib.pyplot as plt

N = 10000
x = [i for i in range(1, N)]
y = []
s = 0

for i in range(1, N):
	n = float(i)
	an = (2*n - 1) / (3 * n)
	if i % 2: an *= -1
	#print(s)
	s += an
	y.append(s)

print(f"\n Sn = {s}")
print(f" For n = {N}")
plt.scatter(x, y)
plt.grid()
plt.show()

