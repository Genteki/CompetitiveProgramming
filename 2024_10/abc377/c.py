# c.py
import collections
n,m = map(int, input().split())
d =  collections.OrderedDict()

f1 = [1, 1, -1, -1]
f2 = [1, -1, 1, -1]
K = int(1e9 + 5)
for _ in range(m):
    a, b = map(int, input().split())
    d[K * a + b] = 1
    for i in range(4):
        na = f1[i] * 2 + a
        nb = f2[i] * 1 + b
        if na >= 1 and nb >= 1 and na <= n and nb <= n:
            d[na * K + nb] = 1
    for i in range(4):
        na = f1[i] * 1 + a
        nb = f2[i] * 2 + b
        if na >= 1 and nb >= 1 and na <= n and nb <= n:
            d[na * K + nb] = 1

ans = n * n - len(d)
print(ans)