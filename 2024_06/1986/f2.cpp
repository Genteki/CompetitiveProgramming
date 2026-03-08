// f.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

vector<vector<i64>> adj;
vector<i64> disc, low, parent, subtree_size;
vector<pair<i64, i64>> bridges;
i64 time_counter;

void findBridgesAndSizes(i64 u) {
    disc[u] = low[u] = ++time_counter;
    subtree_size[u] = 1; // Initialize the size of the subtree rooted at u
    
    for (i64 v : adj[u]) {
        if (disc[v] == -1) { // v is not visited
            parent[v] = u;
            findBridgesAndSizes(v);
            
            // Update low[u] based on the discovery time of v
            low[u] = min(low[u], low[v]);

            // Calculate the size of the subtree rooted at u
            subtree_size[u] += subtree_size[v];

            // If the lowest vertex reachable from subtree under v is below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent[u]) {
            // Update low value of u for parent function calls
            low[u] = min(low[u], disc[v]);
        }
    }
}

i64 main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 t;
    cin >> t;
    
    while (t--) {
        i64 n, m;
        cin >> n >> m;
        
        adj.assign(n + 1, vector<i64>());
        disc.assign(n + 1, -1);
        low.assign(n + 1, -1);
        parent.assign(n + 1, -1);
        subtree_size.assign(n + 1, 0);
        bridges.clear();
        time_counter = 0;
        
        for (i64 i = 0; i < m; ++i) {
            i64 u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Find all bridges using Tarjan's algorithm and calculate component sizes
        for (i64 i = 1; i <= n; ++i) {
            if (disc[i] == -1) {
                findBridgesAndSizes(i);
            }
        }
        
        i64 min_pairs = LLONG_MAX;

        // Calculate pairs for each bridge
        for (const auto& bridge : bridges) {
            i64 u = bridge.first;
            i64 v = bridge.second;

            // Calculate component sizes directly
            i64 size_u = subtree_size[v];
            i64 size_v = n - size_u;

            // Calculate pairs
            i64 pairs = (size_u * (size_u - 1)) / 2 + (size_v * (size_v - 1)) / 2;
            min_pairs = min(min_pairs, pairs);
        }
        
        // If there are no bridges, the whole graph is one component
        if (bridges.empty()) {
            min_pairs = (n * (n - 1)) / 2;
        }
        
        cout << min_pairs << "\n";
    }
    
    return 0;
}