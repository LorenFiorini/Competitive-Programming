
def write_map(mapa, title):
	file_path = "/Users/lfiorini/my_projects/404_not_found/maps/" + title
	with open(file_path, "w") as f:
		for line in mapa:
			row = "".join(line) + "\n"
			f.write(row)

def main():
	file_path = "/Users/lfiorini/my_projects/404_not_found/traces/trace_20231104111632.txt"
	with open(file_path, "r") as f:
		lines = f.readlines()
	n = len(lines)
	lvl = 1
	i = 0
	while i < n:
		line = lines[i].split(' ')
		if lines[i][:3] == "Map":
			title = "level_" + str(lvl)
			i += 1
			lvl += 1
			mapa = []
			while i < n:
				line = list(lines[i])
				if line[-1] == '\n':
					line = line[:-1]
				if line[0] == '#':
					break
				mapa.append(line)
				i += 1
			n = len(mapa)
			m = len(mapa[0]) // 2
			title += "-" + str(n) + "x" + str(m) + ".txt"
			print(title, ": ", n, m)
			write_map(mapa, title)
		else:	
			i += 1

main()
