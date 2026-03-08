import sys
input = sys.stdin.readline

t = int(sys.stdin.readline())
for _ in range(t):
    n, q = map(int, sys.stdin.readline().split())
    p = list(map(int, sys.stdin.readline().split()))
    s = sys.stdin.readline().strip()
    # Positions are 1-based
    p = [0] + p
    s = ' ' + s  # 1-based indexing

    parent = [i for i in range(n+2)]  # Union-Find parent
    min_pos = [i for i in range(n+2)]  # Minimum index in the component
    max_pos = [i for i in range(n+2)]  # Maximum index in the component

    def find(u):
        if parent[u] != u:
            orig_parent = parent[u]
            parent[u] = find(parent[u])
            # Path compression
            min_pos[u] = min(min_pos[u], min_pos[orig_parent])
            max_pos[u] = max(max_pos[u], max_pos[orig_parent])
        return parent[u]

    def union(u, v):
        u_root = find(u)
        v_root = find(v)
        if u_root == v_root:
            return
        # Union by rank not necessary here
        parent[v_root] = u_root
        min_pos[u_root] = min(min_pos[u_root], min_pos[v_root])
        max_pos[u_root] = max(max_pos[u_root], max_pos[v_root])

    for i in range(1, n+1):
        if s[i] == 'L' and i > 1:
            union(i, i-1)
        if s[i] == 'R' and i < n:
            union(i, i+1)

    pos = [0] * (n+1)
    for i in range(1, n+1):
        pos[p[i]] = i

    def can_sort():
        for x in range(1, n+1):
            pos_x = pos[x]
            target_pos = x
            if find(pos_x) != find(target_pos):
                return False
        return True

    result = []
    initial_possible = 'YES' if can_sort() else 'NO'
    # Process queries
    q_indices = []
    for _ in range(q):
        idx = int(sys.stdin.readline())
        q_indices.append(idx)

    for idx in q_indices:
        # Flip s[idx]
        if s[idx] == 'L':
            s = s[:idx] + 'R' + s[idx+1:]
        else:
            s = s[:idx] + 'L' + s[idx+1:]

        # Rebuild Union-Find
        parent = [i for i in range(n+2)]
        min_pos = [i for i in range(n+2)]
        max_pos = [i for i in range(n+2)]

        for i in range(1, n+1):
            if s[i] == 'L' and i > 1:
                union(i, i-1)
            if s[i] == 'R' and i < n:
                union(i, i+1)

        if can_sort():
            result.append('YES')
        else:
            result.append('NO')

    for res in result:
        print(res)
