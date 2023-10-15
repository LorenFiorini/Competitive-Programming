

def main():
	#fra = 12
	#pad = ' ' * 5
	#space = ' ' * 36

	#fra = 24
	#pad = '   '
	#space = ' ' * 17

	fra = 60
	pad = ' ' * 10
	space = ' ' * 6


	# 1
	print(pad, end='')
	for i in range(fra):
		print('|' + space, end='')
	print('|', end='')
	print(pad)

	# 2
	s = " 123456789ABCDEF"
	print(pad, end='')
	for i in range(fra):
		print(s[i % 16] + space, end='')
	print(' ')

print("\n")
for i in range(3):
	main()
print("\n")
