import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline
output = lambda x: stdout.write(str(x))

n, c = map(int, input().split())
t = map(int, input().split())


last = -10000
ans = 0
for ti in t:
    if ti - last >= c:
        ans += 1
        last = ti

print(ans)