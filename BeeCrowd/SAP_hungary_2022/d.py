
def rotate(card):
	nxt = [["" for col in range(3)] for row in range(3)]
	for i in range(3):
		for j in range(3):
			nxt[j][-1-i] = card[i][j]
	
	return nxt

def fit(v, card, r, c):
	for i in range(3):
		for j in range(3):
			if card[i][j] != v[r+i][c+j] and v[r+i][c+j] != '0': # and card[i][j] != '0'
				return 0
	return 1

def solve(v, card, n, m):
	ans = 0
	for i in range(n-2):
		for j in range(m-2):
			if fit(v, card, i, j):
				ans += 1
				print(i,j)
	return ans

def main():
	n, m = map(int, input().split())
	v = list()
	
	for i in range(n):
		row = list(input())
		v.append(row)
		
	q = int(input())
	for _ in range(q):
		ans = 0
		card = list()
		for i in range(3):
			row = list(input())
			card.append(row)
		
		ls = [card]
		for rota in range(3):
			ok = 1
			nxt = rotate(ls[-1])
			for pre in ls:
				if pre == nxt:
					ok = 0
			if ok:
				ls.append(nxt)
			
			
		for card in ls:
			ans += solve(v, card, n, m)
			
		print(ans)
		
main()
