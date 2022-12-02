
'''
# First part
def main():
	d = dict()
	d['A'] = d['X'] = 1
	d['B'] = d['Y'] = 2
	d['C'] = d['Z'] = 3
	ans = 0
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')

	for r in inf:
		x, y = r.split()
		ans += d[y]
		if d[x] == d[y]:
			ans += 3
		elif (d[x]==1 and d[y]==2) or (d[x]==2 and d[y]==3) or (d[x]==3 and d[y]==1):
			ans += 6
	inf.close()
	outf.write(str(ans))
	outf.close()
'''

# Secpnd part
def main():
	d = dict()
	d['A'] = d['X'] = 1
	d['B'] = d['Y'] = 2
	d['C'] = d['Z'] = 3
	ans = 0
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')

	for r in inf:
		x, y = r.split()
		if y == 'X':
			ans += (d[x] - 1) if d[x] > 1 else 3
		elif y == 'Y':
			ans += d[x] + 3
		else:
			ans += d[x] % 3 + 7
	inf.close()
	outf.write(str(ans))
	outf.close()


main()

#11906
#11186