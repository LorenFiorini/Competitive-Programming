

class Pod():
	def __init__(self, name, cpu, mem):
		self.name = name
		self.cpu = int(cpu)
		self.mem = int(mem)


def read():
	# Read input2
	f = open("input2.txt", 'r')
	bound = list()
	for row in f:
		name, cpu, mem = map(str, row.split())
		bound.append(Pod(name, cpu, mem))
	f.close()
	# Read result1
	f = open("result1.txt", 'r')
	mx = list()
	flag = 1
	for row in f:
		if flag: flag = 0
		else:
			name, cpu, mem = map(str, row.split())
			mx.append(Pod(name, cpu, mem))
	f.close()
	return bound, mx

def res(bound, mx):
	f = open("result2.txt", 'w')
	f.write("\n\tBelow their boundaries\n")
	f.write("\nIn terms of CPU:\n")
	for i in range(len(mx)):
		if (bound[i].cpu < mx[i].cpu):
			f.write(" " + mx[i].name + "\n")
	#
	f.write("\nIn terms of memory:\n")
	for i in range(len(mx)):
		if (bound[i].mem < mx[i].mem):
			f.write(" " + mx[i].name + "\n")
	#
	f.write("\n\n\tAbove their boundaries\n")
	f.write("\nIn terms of CPU:\n")
	for i in range(len(mx)):
		if (bound[i].cpu > mx[i].cpu):
			f.write(" " + mx[i].name + "\n")
	#
	f.write("\nIn terms of memory:\n")
	for i in range(len(mx)):
		if (bound[i].mem > mx[i].mem):
			f.write(" " + mx[i].name + "\n")
	f.close()
	
def main():
	bound, mx = read()
	res(bound, mx)

if __name__ == "__main__":
	main()
