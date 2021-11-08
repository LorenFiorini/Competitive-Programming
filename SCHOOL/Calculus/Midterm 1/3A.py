import math
import matplotlib.pyplot as plt

N = 10000
x = [i for i in range(1, N)]
ya = []
yb = []

for i in range(1, N):
	n = float(i)
	an = - (-1 + n**3) ** float(1/3) 
	bn = (n ** 3 + 2*n) ** float(1/3)
	print(an, "\t", bn, "\t", bn + an)
	ya.append(an)
	yb.append(bn)


plt.scatter(x, ya)
plt.scatter(x, yb)
plt.grid()
plt.show()

