# d.py
import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline

n, m = map(int, input().split())

g = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)

q = []
viewed = [False for _ in range(n)]
q.append((0, 0))
while len(q) > 0:
    u, l = q.pop(0)
    viewed[u] = True
    for v in g[u]:
        if v == 0:
            print(l + 1)
            exit()
        if not viewed[v]:
            q.append((v, l+1))

print(-1)