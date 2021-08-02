
primes = [2]

for num in range(3, 2000001):
	ok = True
	for pr in primes:
		if num % pr == 0:
			ok = False
			break
		elif pr ** 2 > num:
			break
	if ok:
		primes.append(num)

print(sum(num for num in primes))
