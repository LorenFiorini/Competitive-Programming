

'''
def main():
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')
	ans = 0;
	
	for line in inf:
		#line = str(input())
		p = line.split(',')
		a, b = map(int, p[0].split('-'))
		c, d = map(int, p[1].split('-'))
		if (a <= c and d <= b) or (a >= c and d >= b):
			ans += 1 
		#outf.write(line)

	inf.close()
	outf.write(str(ans))
	outf.close()
'''
def main():
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')
	ans = 0;
	
	for line in inf:
		#line = str(input())
		p = line.split(',')
		a, b = map(int, p[0].split('-'))
		c, d = map(int, p[1].split('-'))
		if b < c or d < a:
			continue
		else:
			ans += 1 
		#outf.write(line)

	inf.close()
	outf.write(str(ans))
	outf.close()

main()
