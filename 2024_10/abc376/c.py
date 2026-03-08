# c.py

import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline
output = lambda x: stdout.write(str(x))

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort()

v = -1
for i in range(n - 1):
    if (a[i] > b[i]):
        print(-1)
        exit(0)

for i in range(n - 2, -1, -1):
    if (b[i] < a[i + 1]):
        print(a[i+1])
        exit(0)

print(a[0])