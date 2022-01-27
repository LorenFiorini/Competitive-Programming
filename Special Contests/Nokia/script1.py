
class Pod():
	def __init__(self, name, cpu, mem):
		self.name = name
		self.cpu = int(cpu)
		self.mem = int(mem)


def read():
	f = open("input1.txt", 'r')
	v = list()
	flag = 0
	for row in f:
		if not flag: flag = 1
		else:
			name, cpu, mem = map(str, row.split())
			v.append(Pod(name, cpu, mem))
	f.close()
	return v


def getMax(v):
	mx = dict()
	for pod in v:
		if pod.name in mx:
			mx[pod.name].cpu = max(mx[pod.name].cpu, pod.cpu)
			mx[pod.name].mem = max(mx[pod.name].mem, pod.mem)
		else:
			mx[pod.name] = pod
	return mx


def tofile(mx):
	f = open("result1.txt", 'w')
	f.write("NAME_OF_POD    MAX_CPU    MAX_MEM\n")
	for pod in mx.values():
		f.write(pod.name + "\t\t" + str(pod.cpu) + "\t\t" + str(pod.mem) + "\n")
	f.close()


def main():
	v = read()
	mx = getMax(v)
	tofile(mx)	

if __name__ == "__main__":
	main()
