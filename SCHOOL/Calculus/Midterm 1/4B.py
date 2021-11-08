import math
import matplotlib.pyplot as plt

N = 100
x = [i for i in range(1, N)]
y = list()
s = list()
suma = 0

for i in range(1, N):
	n = float(i)
	an = ((10 ** n) * n*n) / math.factorial(i) 
	suma += an
	print(suma)
	s.append(suma)
	y.append(an)


plt.scatter(x, y)
plt.scatter(x, s)
plt.grid()
plt.show()

