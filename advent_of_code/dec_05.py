vec = [""] * 9
vec[0] = "B G S C "
vec[1] = "T M W H J N V C"
vec[2] = "M Q S " 
vec[3] = "B S L T W N M"
vec[4] = "J Z F T V G W P"
vec[5] = "C T B G Q H S"
vec[6] = "T J P B W"
vec[7] = "G D C Z F T Q M"
vec[8] = "N S H B P F"

v = []
for i in range(9):
	ls = list(map(str, vec[i].split()))
	v.append(ls)

print(v)
'''
def main():
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')
	ans = 0

	for line in inf:
		l = line.split()
		sz = int(l[1])
		a = int(l[3]) - 1
		b = int(l[5]) - 1
		while sz > 0 and len(v[a]) > 0:
			v[b].append(v[a][-1])
			v[a].pop(-1)
			sz -= 1

	inf.close()
	
	m = max(len(v[i]) for i in range(9))
	for j in range(m, -1, -1):
		for i in range(9):
			if len(v[i]) > j:
				outf.write('[' + str(v[i][j]) + '] ')
			else:
				outf.write("     ")
			##outf.write('[' + str(v[i]) + ']')
		outf.write('\n')

	for i in range(1, 10):
		outf.write(" " + str(i) + " ")
	outf.write('\n')
	
	for i in range(9):
		if len(v[i]) > 0:
			outf.write(str(v[i][-1]))
	outf.close()
'''
def main():
	inf = open('inputf.in', 'r')
	outf = open('outputf.out', 'w')
	ans = 0

	for line in inf:
		l = line.split()
		sz = int(l[1])
		a = int(l[3]) - 1
		b = int(l[5]) - 1
		sta = max(len(v[a]) - sz, 0)
		
		v[b].extend(v[a][sta:])
		v[a] = v[a][0:sta]
		''''
		while sz > 0 and len(v[a]) > 0:
			v[b].append(v[a][-1])
			v[a].pop(-1)
			sz -= 1
		'''
	for i in range(9):
		if len(v[i]) > 0:
			outf.write(str(v[i][-1]))
	outf.close()
	inf.close()
main()
