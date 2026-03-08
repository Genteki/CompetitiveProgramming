# b.py
import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline

t = int(input())

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    last = 0
    b = []
    for i, ai in enumerate(a):
        if len(b) == 0:
            b.append(n * ai)
            last = ai
            continue
        bi = (ai - last) * (n - i) + b[-1]
        last = ai
        b.append(bi)
    
    for i, bi in enumerate(b):
        if bi >= k:
            print(k + i)
            return

for _ in range(t):
    solve()
            