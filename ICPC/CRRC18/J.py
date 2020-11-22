import re

p = input()
t = input()

pattern = re.compile(p)
u = pattern.match(t)
if u and u.span()[1] == len(t):
    print('Yes')
else:
    print('No')
