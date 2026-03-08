# e.py
import sys
import threading
import bisect
input = sys.stdin.readline

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    p_q = list(map(int, sys.stdin.readline().split()))
    p_k = list(map(int, sys.stdin.readline().split()))
    p_j = list(map(int, sys.stdin.readline().split()))
    players = [('q', p_q), ('k', p_k), ('j', p_j)]

    # Initialize graph
    graph = [[] for _ in range(n + 1)]
    for name, p in players:
        # Build pos_p mapping: pos_p[a] = index of card a in player's preference list
        pos_p = [0] * (n + 1)
        for idx, card in enumerate(p):
            pos_p[card] = idx + 1  # 1-based index

        # Initialize segment tree
        size = 1
        while size < n + 2:
            size <<=1
        st_size = size << 1
        st = [float('inf')] * st_size

        # Function to update segment tree
        def update(idx, val):
            idx += size
            st[idx] = val
            idx >>=1
            while idx:
                st[idx] = min(st[idx<<1], st[idx<<1|1])
                idx >>=1

        # Function to query minimal t > c
        def query(l, r):
            l += size
            r += size
            res = float('inf')
            while l < r:
                if l & 1:
                    res = min(res, st[l])
                    l +=1
                if r &1:
                    r -=1
                    res = min(res, st[r])
                l >>=1
                r >>=1
            return res

        # Process player's preference list
        for i in range(n - 1, -1, -1):
            c = p[i]
            # Query for minimal t > c
            if c + 1 <= n:
                t_min = query(c + 1, n + 1)
                if t_min != float('inf'):
                    # Record edge from c to t_min via this player
                    graph[c].append((t_min, name))
            # Insert c into segment tree
            update(c, c)

    # BFS or DFS from node 1 to find if n is reachable
    from collections import deque
    visited = [False] * (n + 1)
    parent = [None] * (n + 1)
    player_edge = [None] * (n + 1)
    queue = deque()
    queue.append(1)
    visited[1] = True
    found = False
    while queue:
        u = queue.popleft()
        if u == n:
            found = True
            break
        for v, pname in graph[u]:
            if not visited[v]:
                visited[v] = True
                parent[v] = u
                player_edge[v] = pname
                queue.append(v)
    if not found:
        print("NO")
    else:
        # Reconstruct path
        path = []
        trades = []
        curr = n
        while curr != 1:
            prev = parent[curr]
            pname = player_edge[curr]
            path.append(curr)
            trades.append((pname, curr))
            curr = prev
        path.append(1)
        path.reverse()
        trades.reverse()
        print("YES")
        print(len(trades))
        for pname, card in trades:
            print(f"{pname} {card}")