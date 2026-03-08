// e.cpp

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
struct DSU {
    std::vector<int> root, rank;
    int find_root(int node) {
        return root[node] == node ? node : (root[node] = find_root(root[node]));
    }
    void make_union(int node) {
        root[node] = node;
        rank[node] = 1;
    }
    void init() {
        for (int i = 0; i < root.size(); ++i) make_union(i);
    }
    void unite(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if (a == b) return;
        if (rank[a] < rank[b]) std::swap(a, b);
        root[b] = a;
        rank[a] += rank[b];
    }
    DSU(int n) {
        root.assign(n, 0);
        rank.assign(n, 0);
        init();
    }
    DSU(const DSU& other) {
        root = other.root;
        rank = other.rank;
    }
};
void solve() {
    int q, n;
    cin >> n >> q;
    vector<set<int, greater<int>>> g(n);
    for (int i = 0; i < n; ++i) {
        g[i].insert(i);
    } 
    DSU dsu(n);
    debug(n, q);
    for (;q--;) {
        int in;
        cin >> in;
        debug(in, dsu.root);
        if (in == 1) {
            int v, u;
            cin >> u >> v;
            --u; --v;
            u = dsu.find_root(u); 
            v =  dsu.find_root(v);
            if (u == v) continue;
            dsu.unite(u, v);
            if (g[u].size() < g[v].size()) swap(u, v);
            for (auto vi : g[v]) g[u].insert(vi);
            g[v] = set<int, greater<int>>();
        } else {
            int v, k;
            cin >> v >> k;
            --v;
            int root = dsu.find_root(v);
            if (k > (g[root].size())) {
                cout << -1 << endl;
                continue;
            } 
            debug(v, root, g[root]);
            auto it = g[root].begin();
            for(;k > 1; ++it) {
                // if (*it == v) {continue;}
                --k;
            }
            cout << (*it + 1) << endl;
        }
    }

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}