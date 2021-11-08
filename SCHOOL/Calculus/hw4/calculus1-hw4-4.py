import pandas as pd
import matplotlib.pyplot as plt

y = list()
x = list()

for n in range(1, 102):
	x.append(n)
	y.append(((2) ** (2 * n) + (-4) ** n + n ** 2) ** (1 / float(n)))


for i in range(len(x)):
	print(x[i], " ", y[i])

plt.scatter(x, y)
plt.grid()
plt.show()
#plt.savefig('calculus1-hw4-4(1).png')
