import math
import matplotlib.pyplot as plt

N = 10
x = [i for i in range(1, N)]
y = list()
s = list()
suma = 0

for i in range(1, N):
	n = float(i)
	an = (5 ** (2*n)) / (math.factorial(2*n))
	if (i % 2 == 1):
		an *= -1
	suma += an
	print(suma)
	s.append(suma)
	y.append(an)


plt.scatter(x, y)
plt.scatter(x, s)
plt.grid()
plt.show()

