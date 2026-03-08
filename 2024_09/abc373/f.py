import sys
from heapq import *
input = sys.stdin.readline

N, W = map(int, input().split())
x = [[] for _ in range(W+1)]
inf = int(1e10)
for _ in range(N):
    wi, vi = map(int, input().split())
    heappush(x[wi], - (vi - 1))
    
m = [[0] for _ in range(W + 1)]
for wi in range(1, W + 1):
    base = 0
    while len(x[wi]) > 0 and (len(m[wi]) - 1) * wi <= (W + 1):
        vi = heappop(x[wi])
        base += (-vi)
        m[wi].append(base)
        vi += 2
        if (vi < 0): heappush(x[wi], vi)
dp = [-inf] * (W+1)
dp[0] = 0

new_dp = dp.copy()
for w in range(1, W + 1):
    for wi in range(1, W + 1):
        for k in range(1, min(1 + (wi) // w, len(m[w]))):
            new_dp[wi] = max(dp[wi - k * w] + m[w][k], new_dp[wi])
    dp = new_dp.copy()


print(max(dp))