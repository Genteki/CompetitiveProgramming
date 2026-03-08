def solve():
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    
    if sum(a) != n:
        print(-1)
        return
    
    positions = sorted(zip(x, a))
    
    ans = 0
    cur = 1
    pos = 0
    
    for xi, ai in positions:
        distance = xi - pos
        new_cur = cur - distance
        
        if new_cur < 0: 
            print(-1)
            return
        
        ans += (cur - 1 + new_cur) * distance // 2
        cur = new_cur + ai
        pos = xi
    
    ans += (cur - 1) * cur // 2
    print(ans)

solve()