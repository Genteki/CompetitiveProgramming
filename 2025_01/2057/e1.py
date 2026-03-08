class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        
        if rootX != rootY:
            # Union by rank
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

def solve():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    index = 0
    t = int(data[index])  # number of test cases
    index += 1
    results = []
    
    for _ in range(t):
        n, m, q = map(int, data[index].split())  # n: number of vertices, m: number of edges, q: number of queries
        index += 1
        
        edges = []
        for __ in range(m):
            v, u, w = map(int, data[index].split())
            edges.append((w, v-1, u-1))  # store edges as (weight, vertex1, vertex2)
            index += 1
        
        queries = []
        for __ in range(q):
            a, b, k = map(int, data[index].split())
            queries.append((a-1, b-1, k))  # store queries as (vertex1, vertex2, k-th max)
            index += 1
        
        # Sort edges by weight in descending order
        edges.sort(reverse=True, key=lambda x: x[0])
        
        # For each query, process the edges and check connectivity
        for a, b, k in queries:
            # Use DSU to find the k-th largest edge in the path
            dsu = DSU(n)
            edge_weights = []
            
            # Process edges to construct possible valid paths
            for weight, u, v in edges:
                dsu.union(u, v)
                if dsu.find(a) == dsu.find(b):
                    edge_weights.append(weight)
                
                # Stop once we have enough edges
                if len(edge_weights) >= k:
                    break
            
            edge_weights.sort(reverse=True)
            # Return the k-th largest weight
            results.append(str(edge_weights[k-1]))
    
    # Output all results for all queries
    sys.stdout.write("\n".join(results) + "\n")
solve()