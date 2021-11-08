import math
import matplotlib.pyplot as plt

N = 100
x = [i for i in range(1, N)]
y = list()
s = list()
suma = 0

for i in range(1, N):
	n = float(i)
	X = 1.1/2
	an = ((2 * X - 3) ** (2*n)) / (4 ** (n+1))
	if i % 2: an *= -1
	suma += an
	print(an)
	s.append(suma)
	y.append(an)


plt.scatter(x, y)
plt.scatter(x, s)
plt.grid()
plt.show()

