class Node:
    def __init__(self, b, p, a):
        self.b = b
        self.p = p
        self.a = a

ns = [Node(0,0,0)]
stk = []
v = []

T = int(input())
kase = 0
while T > 0:
    T = T - 1
    n = int(input())
    for i in range(1,n+1):
        a = int(input())
        tmpa = ns[-1].a
        ns.append(Node(0,0,tmpa+a))
    for i in range(1,n+1):
        ns[i].b = int(input())
        ns[i].p = i
        if(i!=1):
            ns[i].b = min(ns[i-1].b,ns[i].b)
    while len(stk) != 0:
        stk.pop()
    v.clear()
    for i in reversed(range(1,n+1)):
        while len(stk) != 0:
            l = stk[0]
            if ns[i].a >= ns[l].a:
                stk.pop()
            else:
                break
        stk.append(i)

    while len(stk) != 0:
        v.append(stk[-1])
        stk.pop()
    length = len(v)
    ans = 0
    for i in reversed(range(length)):
        if i == length - 1:
            ans = ans + ns[v[i]].a * ns[v[i]].b
        else:
            ans = ans + ns[v[i]].a * (ns[v[i]].b - ns[v[i+1]].b)
    print('Case #{}: {} {}'.format(kase, ns[0].b,ans))
    kase = kase + 1
    
