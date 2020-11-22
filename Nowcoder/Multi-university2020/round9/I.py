import random

T = int(input())
while T > 0:
    T = T - 1
    n = int(input())
    lis = list([x for x in input().split(' ')])
    lis.sort()
    pos = 0
    for i in range(len(lis)):
        if lis[i] != '0':
            pos = i
            break
    a = lis[pos]
    b = lis[pos + 1]
    leng = len(lis)
    b = b + ''.join(lis[0 : pos])
    if pos + 2 < leng:
        suf = lis[pos + 2 : leng]
        suf = ''.join(suf)
        b = b + suf
    b = int(b)
    a = int(a)
    # print('T = ' + str(T))
    print(a * b)
