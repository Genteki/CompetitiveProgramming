# d.py

H, W, K = map(int, input().split())
m = [input() for _ in range(H)]

cell_index = {}
index_cell = {}
idx = 0
for i in range(H):
    for j in range(W):
        if m[i][j] == '.':
            cell_index[(i, j)] = idx
            index_cell[idx] = (i, j)
            idx += 1

N = idx

g = [[] for _ in range(N)]
for idx in range(N):
    i, j = index_cell[idx]
    for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
        ni, nj = i+dx, j+dy
        if 0<=ni<H and 0<=nj<W and m[ni][nj]=='.':
            g_idx = cell_index[(ni, nj)]
            g[idx].append(g_idx)

ans = 0

def dfs(pos, visited, steps):
    global ans
    if steps == K:
        ans += 1
        return
    for nei in g[pos]:
        if not visited[nei]:
            visited[nei] = True
            dfs(nei, visited, steps+1)
            visited[nei] = False

for start in range(N):
    visited = [False]*N
    visited[start] = True
    dfs(start, visited, 0)

print(ans)