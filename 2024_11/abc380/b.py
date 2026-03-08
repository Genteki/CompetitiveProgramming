# b.py

s = list(input())
l = []
for si in s:
    if si == '|':
        l.append(0)
    else:
        l[-1] += 1

l.pop(-1)
for ans in l:
    print(ans, end = " ")
    