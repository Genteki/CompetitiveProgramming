# c

from collections import defaultdict
n = int(input())
a =  list(map(int, input().split()))

d = defaultdict(lambda: -2)
b = []
for i in range(n):
    b.append(d[a[i]] + 1)
    d[a[i]] = i
    
print(*b, sep=" ")