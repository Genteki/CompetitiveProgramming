t = int(input())
for _ in range(t):
    n = int(input())
    x = 0
    y = 0
    for _ in range(n):
        a, b = map(int, input().split())
        x = max(x, a)
        y = max(y, b)
    
    print(2*(x + y))