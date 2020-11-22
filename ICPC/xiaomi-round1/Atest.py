n = 200000

f = open('A.in', 'w+')
f.write(str(n))
val = 1
for i in range(n):
    f.write('{} '.format(val))
    val *= 2
f.close()
