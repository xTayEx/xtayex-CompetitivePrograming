from random import randint

f = open('./HDU3551.in', 'w+')
f.write('1\n')
f.write('50 200\n')
for i in range(200):
    u = randint(1, 50)
    v = randint(1, 50)
    f.write(str(u) + ' ' + str(v) + '\n')
f.close()
