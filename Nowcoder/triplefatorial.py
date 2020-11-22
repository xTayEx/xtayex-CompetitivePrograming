fac = [1]
for i in range(1, 10001):
    fac.append(fac[i - 1] * i)

print(fac[fac[4]])
while True:
    n, m = [int(x) for x in input().split()]
    print(fac[fac[fac[n]]] % m)
