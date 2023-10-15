

def main():
	fin = open("recommendation.txt", 'r')
	fout = open("recommendation_out.txt", 'w')

	txt = fin.read()
	ls = list(txt)

	for c in ls:
		if c == "\n":
			fout.write(' ')
		else:
			fout.write(c)

	fin.close()
	fout.close()

main()
