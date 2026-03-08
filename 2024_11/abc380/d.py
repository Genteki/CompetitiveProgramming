# d.py
import sys
s = list(input())
q = map(int, input())
qs = list(map(int, input().split()))
n = len(s)

for qi in qs:
    m = n
    k = 0
    flip = False
    while m < qi:
        m *= 2
        k += 1
    
    m = n
    while k > 0:
        k -= 1
        print(k, qi, m, file=sys.stderr)
        if qi > m << k:
            qi -= m << k 
            flip = not flip
            
    ans = s[qi-1]
    if flip:
        if 'a' <= ans <= 'z':
            ans = chr(ord(ans) - ord('a') + ord('A'))
        elif 'A' <= ans <= 'Z':
            ans = chr(ord(ans) - ord('A') + ord('a'))
        
    print(ans, end = ' ')