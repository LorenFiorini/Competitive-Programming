
def ok(H, M, S, i, res):
	if (((i*M) % H) != 0) or (((i*S) % H) != 0): 
		return False
	res[1] = (i * M) // H
	res[2] = (i * S) // H
	return True


def main():
	H, M, S = map(int, input().split())
	ans = list()
	
	for i in range(H):
		res = [i, 0, 0]
		if ok(H, M, S, i, res):
			ans.append(res)

	print(len(ans))
	for a in ans:
		print(a[0], a[1], a[2])
	
main()
