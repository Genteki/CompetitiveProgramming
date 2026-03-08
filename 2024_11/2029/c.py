# c.py
import sys
import threading
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    x = 0
    x_list = [0]
    s_list = []
    for ai in a:
        if ai > x:
            s = 1
        elif ai == x:
            s = 0
        else:
            s = -1
        x += s
        x_list.append(x)
        s_list.append(s)
    # Find minimal sum subarray in s_list
    min_sum = s_list[0]
    current_sum = s_list[0]
    for s in s_list[1:]:
        current_sum = min(s, current_sum + s)
        min_sum = min(min_sum, current_sum)
    max_rating = x - min_sum
    print(max_rating)

