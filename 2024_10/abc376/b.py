# b.py

import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline
output = lambda x: stdout.write(str(x))

N, Q = map(int, input().split())
ans  = 0
left, right = 1, 2
d = (N + 1) // 2
for _ in range(Q):
    print(left, right)
    hand, pos = input().split()
    pos = int(pos)
    
    
    if hand == "L":
        a, b = left, right
    else:
        a, b = right, left
    
    dab = (b - a + N) % N
    dap = (pos - a + N) % N
    if dap > dab:
        ans += (N - dap)
    else:
        ans += dap
    a = pos
print(ans)