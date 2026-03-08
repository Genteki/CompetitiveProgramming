# c.py

n, k = map(int, input().split())
s = list(input())
l = []
l.append([s[0], 1])
for i in range(1, n):
    if s[i] == s[i - 1]:
        l[-1][1] += 1
    else:
        l.append([s[i], 1])

j = 0
if l[0][0] == '1':
    j = k * 2 - 2
else:
    j = k * 2 - 1

l[j-2][1] += l[j][1]
l[j][1] = 0

if j + 1 < len(l):
    l[j-1][1] += l[j+1][1]
    l[j+1][1] = 0

for char, num in l:
    print(char * num, end = '')