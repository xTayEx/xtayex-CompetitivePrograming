from random import randint

direction = ['W', 'A', 'S', 'D']

f = open('./I.in', 'w+')
T = 100
f.write(str(T) + '\n')
while T > 0:
    T -= 1
    n, m = randint(2, 1000), randint(2, 1000)
    f.write('{} {}\n'.format(n, m))
    for row in range(n):
        for col in range(m):
            ch = direction[randint(0, 3)]
            f.write(ch)
        f.write('\n')
f.close()
