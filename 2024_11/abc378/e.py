# e.py
from sortedcontainers import SortedList

n, m = map(int, input().split())
a = list(map(int, input().split()))
for ai in a:
    ai = ai % m
print(a)

ans = 0
ps = [0 for _ in range(n + 1)]
for i in range(n):
    ps[i + 1] = (ps[i] + a[i]) % m
ps2 = [0 for _ in range(n + 2)]
md2 = [0 for _ in range(n + 2)]
for i in range(n + 2):
    ps2[i + 1] = (ps2[i] + ps[i]) % m
    md2[i + 1] = md2[i] + (ps2[i] + ps[i]) // m;

ps2 = [0]
d = defaultdict
    
print(ans)