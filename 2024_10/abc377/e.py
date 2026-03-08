N, K = map(int, input().split())
P = list(map(int, input().split()))

visited = [False]*N
res = [0]*N

for i in range(N):
    if not visited[i]:
        cycle = []
        x = i
        while not visited[x]:
            visited[x] = True
            cycle.append(P[x])
            x = P[x] - 1 
        L = len(cycle)
        M = pow(2, K, L)
        for idx in range(L):
            res[cycle[idx] - 1] = cycle[(idx + M) % L]
            
print(' '.join(map(str, res)))