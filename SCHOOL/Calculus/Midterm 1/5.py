import math
import matplotlib.pyplot as plt

N = 5
x = [i for i in range(1, N)]
y = list()
s = list()
suma = 0

for i in range(1, N):
	n = float(i)
	an = ((4 ** (n+1)) / (n + 3)) * ((-3) ** n)
	suma += an
	print(an)
	s.append(suma)
	y.append(an)


plt.scatter(x, y)
plt.scatter(x, s)
plt.grid()
plt.show()

