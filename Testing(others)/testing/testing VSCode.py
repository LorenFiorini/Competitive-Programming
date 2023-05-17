

def dfs(a, p):
    if p == len(a):
        return 1
    return dfs(a, p+1) * a[p] 

print(dfs(list(range(1,10)) , 0))
