import math

T = int(input())
while T > 0:
    T = T - 1
    x, y, k = [int(x) for x in input().split(' ')]
    up = k + y * k - 1
    down = x - 1
    tmp = up / down
    ans = math.ceil(tmp) + k
    if tmp * down < up:
        ans = ans + 1
    elif tmp * down > up:
        ans = ans - 1
    print(int(ans))
