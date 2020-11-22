import numpy as np

n = int(input())

lst = []

def gcd(u, v):
    if (v == 0):
        return u
    return gcd(v, u % v)

def fabs(u):
    if u >= 0:
        return u
    return -u

def dfs(dep, k):
    if (dep == -1):
        lst.append(''.join([str(x) for x in k]))
        return
    
    k[dep] = 0
    dfs(dep - 1, k.copy())
    k[dep] = 1
    dfs(dep - 1, k.copy())

dfs(n * n - 1, [0 for i in range(n * n)])

lst.sort()
print(lst)

ans = 0
for x in lst:
    if fabs(np.linalg.det(x)) < 1e-10:
        ans = ans + 1

u, v = ans, len(lst)
temp = gcd(u, v)
u, v = u // temp, v // temp
print(str(u) + "/" + str(v))
