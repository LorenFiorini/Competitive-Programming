
import matplotlib.pyplot as plt
x = []
y = []
s = 0

for i in range(1, 10000):
	n = float(i)
	an = (1 / (n ** 10 + 6 * n + 1)) ** (1 / n)
	print(an)
	s += an
	x.append(n)
	y.append(s)

plt.scatter(x, y)
plt.grid()
plt.show()

