
import sys
import matplotlib.pyplot as plt

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

def get(name, pods):
	cpu = list()
	mem = list()
	for pod in pods:
		if name == pod.name:
			cpu.append(pod.cpu)
			mem.append(pod.mem)
	x = [i+1 for i in range(len(cpu))]
	plt.scatter(x, cpu) # BLUE
	plt.scatter(x, mem) #orange
	plt.grid()
	plt.show()
	

def main(arg):
	pods = read()
	##fig, axs = plt.subplots(len(arg), 1)
	for name in arg:
		get(name, pods)
		
	plt.show()

if __name__ == "__main__":
   main(sys.argv[1:])
   
