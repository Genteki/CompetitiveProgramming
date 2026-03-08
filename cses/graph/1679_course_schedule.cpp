#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>()), g_(n, vector<int>());
    bool c = false;
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g_[u].push_back(v);
        g[v].push_back(u);
        if (u == v) {
            c = true;
        }
    }
    if (c) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> used(n, 0);
    vector<int> order;
    auto dfs1 = [&](auto && self, int u) -> void {
        if (used[u]) return;
        used[u] = 1;
        for (auto v : g[u]) {
            if (!used[v]) self(self, v);
        }
        order.push_back(u);
    };
    for (int i = 0; i < n; ++i) {
        if (g_[i].size() == 0 || !used[i]) {
            dfs1(dfs1, i);
        }
    }
    memset(used.data(), 0, n * sizeof(int));
    vector<int> roots(n, -1);
    auto dfs2 = [&](auto && self, int u, int p) -> void {
        if (used[u]) return;
        used[u] = 1;
        roots[u] = p;
        for (auto v : g_[u]) {
            if (!used[v]) {
                self(self, v, p);
            }
        }
    };
    reverse(all(order));
    for (auto u : order) {
        if (!used[u]) {
            dfs2(dfs2, u, u);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i != roots[i]) {
            cout << "IMPOSSIBLE" <<endl;
            return;
        }
    }
    
    reverse(all(order));
    for (auto oi : order) cout << (oi+1) << " "; cout << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}