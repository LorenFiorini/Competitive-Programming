
import matplotlib.pyplot as plt
x = []
y = []
s = 0

for n in range(1, 100):
	an = (3 * n*n + n ** 0.5 + 2) / (2 * (n**6) - n ** 4 + 3 * n)
	s += an
	x.append(n)
	y.append(s)
	print(s)

plt.scatter(x, y)
plt.grid()
plt.show()

