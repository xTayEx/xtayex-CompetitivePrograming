n = input()
s = ''
for it in n:
    if it == '(':
        s += '**'
    s += it

print(eval(s))
