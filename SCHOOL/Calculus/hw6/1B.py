import math
import matplotlib.pyplot as plt

N = 30
x = []
y = []
s = 0

for i in range(1, N):
	n = float(i)
	an = math.factorial(2 * n) / ((3 ** n) * (math.factorial(n) ** 2))
	print(an)
	s += an
	x.append(n)
	y.append(s)

print(f"\n Sn = {s}")
print(f"For n = {N}")
plt.scatter(x, y)
plt.grid()
plt.show()

