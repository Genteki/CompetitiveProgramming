// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
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
typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m;
    cin >> n >> m;
    vector x(n, vector<i64>(11, 0));
    for (i64 i = 0; i < m; ++i) {
        i64 a, d, k;
        cin >> a >> d >> k;
        --a;
        x[a][d] = max(x[a][d], k);
    }
    DSU dsu(n);
    vector<bool> viewed(n, false);
    i64 cc = 0;
    auto dfs = [&](auto&& self, i64 u, int p) -> void {
        if (viewed[u]) return;
        viewed[u] = true;
        for (i64 d = 1; d <= 10; ++d) {
            for (i64 k = 1; k <= x[u][d]; ++k) {
                dsu.unite(p, u + k * d);
                p = dsu.find_root(p);
                if (!viewed[u + k * d]) {
                    self(self, u + k * d, p);
                }
            }
        }
    };
    for (i64 i = 0; i < n; ++i) {
        if (!viewed[i]) {
            dfs(dfs, i, i);
        }
    }
    debug(0);
    // for (int i = 0; i < n; ++i) {
    //     dsu.find_root(i);
    // }
    for (int i = 0; i < n; ++i) {
        if (dsu.find_root(i) == i) {
            ++cc;
        }
    }
    debug(0);

    cout << cc << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
