import random

lis = [x for x in range(1, 6)]
seq = []

while len(seq) <= 500000:
    random.shuffle(lis)
    seq = seq + lis

f = open('./Kgen.in', 'w+')
f.write('1\n')
f.write('{} 5\n'.format(len(seq)))
for item in seq:
    f.write('{} '.format(item))
f.close()
