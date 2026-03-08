import sys, math
from math import gcd,floor,sqrt,log
from collections import defaultdict
from bisect import bisect_left, bisect_right
from heapq import *
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    a, b = map(int, input().split());
    if (a > b):
        print(a)
    elif (a * 2 <= b):
        print(0)
    else:
        print(a - (b-a))