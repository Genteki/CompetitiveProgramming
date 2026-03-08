// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
struct DSU {
    std::vector<int> root, rank;
    DSU(int n) { init(n); }
    void init(int n) {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        rank.assign(n, 1);
    }
    int find(int x) {
        while (x != root[x]) {
            x = root[x] = root[root[x]];
        }
        return x;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) std::swap(a, b);
        root[b] = a;
        rank[a] += rank[b];
        return true;
    }
    DSU(const DSU& other) {
        root = other.root;
        rank = other.rank;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<array<int,2>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        edges[i][0] = u;
        edges[i][1] = v;
    }
    vector<int> to_change;
    for (int i = 0; i < m; ++i) {
        auto [u, v] = edges[i];
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
        } else {
            to_change.push_back(i);
        }
    }
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            roots.push_back(i);
        }
    }
    cout << roots.size() - 1 << endl;
    debug(roots);
    debug(to_change);
    int y = roots.size()-1;
    for (int i = 0; i < y; ++i) {
        int u, v, w;
        u = edges[to_change[i]][0];
        v = edges[to_change[i]][1];
        if (dsu.find(u) == dsu.find(roots.back())) {
            swap(roots.back(), roots[0]);
        }
        cout << (to_change[i]+1) << " " << (1+v) << " " << (roots.back()+1) << " " << endl;
        dsu.unite(u, roots.back());
        roots.pop_back(); 
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}