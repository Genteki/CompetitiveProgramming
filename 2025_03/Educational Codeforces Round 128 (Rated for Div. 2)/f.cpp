#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

struct Edge {
    int u, v;
};

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<pair<int,int>>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[i] = Edge{u, v};
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<int> viewed_vertex(n, 0), viewed_edge(m, 0), used_vertex(n,0);
    int cnt = 0;
    auto dfs = [&](this auto&& self, int u, int c = 1, int p = -1) -> void {
        viewed_vertex[u] = 1;
        if (c == 1) {
            used_vertex[u] = 1;
            for (auto [v, i] : g[u]) {
                viewed_edge[i] = 1;
            }
        }
        for (auto [v, i] : g[u]) {
            if (v == p) continue;
            if (!viewed_vertex[v]) {
                viewed_vertex[v] = 1;
                self(v, 1 - c, u);
            }
        }
    };
    dfs(0);
    debug(used_vertex);
    debug(viewed_vertex);
    int x = accumulate(viewed_edge.begin(), viewed_edge.end(), 0);
    debug(x);
    if (m - x == 0) {
        cout << "YES\n";
        for (auto i : used_vertex) cout << i;
        cout << endl;
        return;
    } else if (m-x == 1) {
        cout << "YES\n";
        for (int i = 0; i < m; ++i) {
            if (viewed_edge[i] == 0) {
                auto [u, v] = edges[i];
                if (!used_vertex[u]) {
                    for (auto & ui : used_vertex) ui = 1- ui;
                }
            }
        }
        for (auto i : used_vertex) cout << i;
        cout << endl;
        return;
    }
    for (auto &ui : used_vertex) {ui = 1 - ui;}
    fill(viewed_edge.begin(), viewed_edge.end(), 0);
    int y = 0;
    for (int i = 0; i < n; ++i) {
        if (used_vertex[i]) {
            for (auto[_, j] : g[i]) {
                viewed_edge[j] = 1;
                ++y;
            }
        }
    }
    x = accumulate(viewed_edge.begin(), viewed_edge.end(), 0);
    debug(x, y);
    if (x == m and y - m <= 1) {
        cout << "YES" << endl;
        for (auto i : used_vertex) cout << i;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}