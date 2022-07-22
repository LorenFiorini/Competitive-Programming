
import math

a, b, d = map(float, input().split())

de = float(d * math.pi) / float(180.0)
x = math.cos(de) * a - math.sin(de) * b
y = math.sin(de) * a + math.cos(de) * b 

#print(round(x, 7), round(y, 7))
print("{0:0.20f}".format(x), end=" ")
print("{0:0.20f}".format(y))
