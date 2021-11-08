
import matplotlib.pyplot as plt
x = []
y = []
s = 0

for i in range(1, 100):
	n = float(i)
	an = ((n*n + 6) / (n*n + 4)) ** (n**3)
	an *= (n*n) / (3 ** (2*n - 1))
	print(an)
	s += an
	x.append(n)
	y.append(s)

print(f"\n Sn = {s}")
plt.scatter(x, y)
plt.grid()
plt.show()

