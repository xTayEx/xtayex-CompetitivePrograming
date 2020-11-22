f = open("./A.in","w+")
f.write("2000000")
f.write('\n')
for i in range(1,6000001):
    f.write(str(i) + '\n')
f.close()
