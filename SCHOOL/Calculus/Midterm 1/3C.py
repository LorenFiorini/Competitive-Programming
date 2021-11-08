import math
import matplotlib.pyplot as plt

N = 10000
x = list()
y = list()

for i in range(1, N, 10):
	n = float(i)
	an = float((n*n + 5*n - 6) / (n*n - 2*n - 2))
	print(an)
	an **= 3*n  + 2
	y.append(an)
	print(an)
	x.append(i)
	


plt.scatter(x, y)
plt.grid()
plt.show()

