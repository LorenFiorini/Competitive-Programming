
import math


if __name__ == "__main__" :
	ans = 0
	n = int(input())
	mp = dict()
	for i in range(n):
		tmp = str(input())
		if tmp[0] in mp:
			mp[tmp[0]] += 1
		else:
			mp[tmp[0]] = 1
	
	for i in mp:
		#print(i)
		#print(mp[i])
		a = b = int(mp[i] // 2)
		if mp[i] % 2 == 1:
			b += 1
		
		if a >= 2:
			res = math.comb(a, 2)
			#print(res)
			ans += res
		
		if b >= 2:
			res = math.comb(b, 2)
			#print(res)
			ans += res
	
	
	print(ans)
