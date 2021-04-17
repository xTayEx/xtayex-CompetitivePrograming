from math import gcd

primes = []

def init():
    pass

while True:
    p, q = [int(x) for x in input().split(' ')]
    print('gcd({}, {}) = {}'.format('p + q', 'p * q', gcd(p + q, p * q)))

