import math
import matplotlib.pyplot as plt

N = 100
x = [i for i in range(1, N)]
y = list()
s = list()
suma = 0

for i in range(1, N):
	n = float(i)
	an = 1 / (n + n ** (1/n))
	if i % 2: an *= -1
	suma += an
	print(suma)
	s.append(suma)
	y.append(an)


plt.scatter(x, y)
plt.scatter(x, s)
plt.grid()
plt.show()

