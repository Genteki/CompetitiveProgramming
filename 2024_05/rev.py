import sys
s = ""
with open("cp.txt") as f:
    for line in f.readlines():
        s = (s + line[::-1])

print(s)

