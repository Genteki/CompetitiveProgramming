# c.py
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    has_large_group = False
    count = 0
    for c in s:
        if c == '1':
            count += 1
            if count > 1:
                has_large_group = True
                break
        else:
            count = 0
    print("YES" if has_large_group else "NO")