import math
import matplotlib.pyplot as plt

N = 300
x = [i for i in range(1, N)]
y = list()

for i in range(1, N):
	n = float(i)
	an = ((5 ** n + 3*n + n**2) / (n + 2)) ** float(1/n) 
	y.append(an)


plt.scatter(x, y)
plt.grid()
plt.show()

