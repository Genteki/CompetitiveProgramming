# b.py

n, k = map(int, input().split())
s = input()
last = -1
ans = 0
for i in range(n):
    if s[i] == 'O':
        if (i - last) >= k:
            ans += 1
            last = i
    else:
        last = i
print(ans)