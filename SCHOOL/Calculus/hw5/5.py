
import matplotlib.pyplot as plt
x = []
y = []
s = s10 = 0

for i in range(1, 400):
	n = float(i)
	an = (2 ** n) / (3 ** (n+1) + 5 ** n + n ** 0.5)
	print(an)
	s += an
	if i == 10:
		s10 = s
	x.append(n)
	y.append(s)

print("|E| = ", s - s10)
print(s)
print(s10)
plt.scatter(x, y)
plt.grid()
plt.show()

