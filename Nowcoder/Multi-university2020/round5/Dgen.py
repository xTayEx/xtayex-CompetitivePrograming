import random

lis = [x for x in range(1, 501)]
random.shuffle(lis)
print(lis)

f = open('./D.in', 'w+')
f.write('500\n')
for item in lis:
    f.write(str(item) + ' ')

