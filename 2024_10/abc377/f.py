from collections import OrderedDict

row = OrderedDict()
col = OrderedDict()
c1 = OrderedDict()
c2 = OrderedDict()

n, m = map(int, input().split())
for _ in range(m):
    y, x = map(int, input().split())
    y -= 1
    x -= 1
    row.add(y)
    col.add(x)
    c1.add(y - x)
    c2.add(y + x)
    
ans = n * len(row) + (n - len(row)) * len(col)



