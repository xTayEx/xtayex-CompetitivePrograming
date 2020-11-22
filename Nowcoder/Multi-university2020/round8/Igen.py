import random

f = open('./I.in','w+')
f.write('100000')
for i in range(100000):
    f.write('{} {}'.format(random.randint(1,1000000000),random.randint(1,1000000000)))
f.close()
