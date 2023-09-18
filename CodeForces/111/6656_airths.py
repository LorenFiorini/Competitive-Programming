import time

def main():
	for _ in range(int(input())):
		n, a, b=tuple(map(int,input().split()))
		s=input()
		ans=0
		if (b>0):
			ans+=n*(a+b)
		else:
			k=s.count('1')
			k2=s.count('0')
			le=s[0]
			l=[]
			lent=0
			for i in range(n):
				if i==n-1 and le==s[i]:
					lent+=1
					l+=[lent]
				elif i==n-1 and le!=s[i]:
					l+=[lent]
					l+=[1]
				elif s[i]==le:
					lent+=1
				else:
					le=s[i]
					l+=[lent]
					lent=1
			# print(l)
			while l!=[]:
				if len(l)>=3:
					ans+=a*(l[len(l)//2]+l[len(l)//2-1]+l[len(l)//2+1])+2*b
					if (len(l)//2+2<=len(l)-1):
						l=l[:len(l)//2-1]+l[len(l)//2+2:]
					else:
						l=l[:len(l)//2-1]
					if (len(l)>=2):
						l=l[:len(l)//2-1]+[l[len(l)//2-1]+l[len(l)//2]]+l[len(l)//2+1:]
					# print(l)
				else:
					if (len(l))==2:
						ans+=a*(l[0]+l[1])+2*b
						break
					else:
						ans+=l[0]*a+b
						break
			# print(l)
		print(ans)
		
if __name__=='__main__':
	st = time.time()
	main()
	end = time.time()
	print("Time: {} ms".format(end-st))
	
