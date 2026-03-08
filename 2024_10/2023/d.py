import heapq, sys, os
input = sys.stdin.readline
output = sys.stdout.write
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n): b[i] -= 1
    inf = int(1e18)
    dp = [inf for _ in range(n)]
    pq = [(0,0)]
    heapq.heapify(pq)
    while len(pq) > 0:
        dpi, i = heapq.heappop(pq)
        if (dp[i] == inf):
            dp[i] = dpi
            if b[i] > i:
                heapq.heappush(pq, ((dpi + a[i]), b[i]))
            if i > 0 and dp[i-1] == inf:
                heapq.heappush(pq, (dpi, i-1))
    ans = 0
    s = 0
    for i in range(n):
        s += a[i]
        ans = max(ans, s - dp[i])
    print(ans)
    
T = int(input())
for _ in range(T):
    solve()