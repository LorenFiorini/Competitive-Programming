


def circularSubstringCompetition(target, source):
	def by_id():
		id = dict()
		alpha = "abcdefghijklmnopqrstuvwxyz"
		for i in range(26):
			id[alpha[i]] = i
		return id
	def check(v, target, id):
		for c in target:
			if v[id[c]] < 0:
				return False 
		return True

	id = by_id()
	target = list(target)
	source = list(source)
	n = len(source)
	m = len(target)
	# initialize count
	ans = n*n
	v = [0 for i in range(26)]
	for c in target:
		v[id[c]] -= 1
	j = 0
	for i in range(n):
		while not check(v, target, id):
			change = 0
			while j <= 2*n and not change:
				if j >= n and i == 0:
					return -1
				v[id[source[j%n]]] += 1
				change = bool(v[id[source[j%n]]] == 0)
				j += 1
		#print(i,j)
		ans = min(ans, j - i)
		if ans == m:
			break
		v[id[source[i]]] -= 1
	return ans

'''
def circularSubstringCompetition(target, source):
	id = dict()
	alpha = "abcdefghijklmnopqrstuvwxyz"
	for i in range(26):
		id[alpha[i]] = i
	
	target = list(target)
	source = list(source)	
	v_target = [0 for i in range(26)]
	for c in target:
		v_target[id[c]] += 1
	v_source = [[0 for i in range(26)]]
	for c in source:
		tmp = list(v_source[-1])
		tmp[id[c]] += 1
		v_source.append(tmp)
	if v_source[-1] < v_target:
		return -1

	return 0
'''

print(circularSubstringCompetition("abc", "aabb"))
print(circularSubstringCompetition("kanah", "hackerrank"))
