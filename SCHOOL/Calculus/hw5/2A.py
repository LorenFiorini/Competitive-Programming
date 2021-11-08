
import matplotlib.pyplot as plt
x = []
y = []
s = 0

for n in range(1, 1000):
	an = (2 ** (3*n + 1) + (-5) ** (n - 1)) / (3 ** (2*n +1))
	s += an
	x.append(n)
	y.append(s)
	print(s)

plt.scatter(x, y)
plt.grid()
plt.show()

