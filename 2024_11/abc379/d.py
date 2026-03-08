# d.py
import bisect
q = int(input())
t = 0
p = []
pointer = 0
for _ in range(q):
    qi = input().split()
    if (qi[0] == '1'):
        p.append(t)
    elif (qi[0] == "2"):
        t += int(qi[1])
    else:
        height = int(qi[1])
        x = bisect.bisect_ringht(p, t-height)
        print(x - pointer)
        pointer = x