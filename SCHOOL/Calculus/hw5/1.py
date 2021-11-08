
import matplotlib.pyplot as plt

x = list()
y = list()
a = 3

for i in range(1, 100):
	print(a)
	x.append(i)
	y.append(a)
	a = (5 * a*a - 4 * a) ** (1/3)
	

plt.scatter(x, y)
plt.grid()
plt.show()
