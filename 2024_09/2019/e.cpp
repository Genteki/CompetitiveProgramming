// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define int i64
void solve() {
    i64 n;
    cin >> n;
    vector g(n, vector<i64>());
    vector g_(n, set<i64>());
    vector<i64> parent(n, -1);
    for (i64 i = 0; i < n - 1; ++i) {
        i64 u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<i64> depth(n, 0);
    map<i64, vector<i64>> leaves;
    map<i64, vector<i64>> nodes;
    auto dfs2 = [&](auto&& self, i64 u, i64 p) -> i64 {
        i64 cnt = 1;
        g_[p].erase(u);
        if (g_[p].empty()) {
            cnt += self(self, p, parent[p]);
        }
        return cnt;
    };

    auto dfs = [&](auto&& self, i64 u, i64 p = -1) -> void {
        parent[u] = p;
        if (p != -1) g_[p].insert(u);
        for (auto v : g[u]) {
            if (v == p) continue;
            debug(u, v);
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
        if (g[u].size() == 1 && g[u][0] == p)  leaves[depth[u]].push_back(u);
        nodes[depth[u]].push_back(u);
    };
    dfs(dfs, 0);
    i64 ans = n-1;
    i64 edge_sum = -1, leave_sum = 0;
    auto it = leaves.begin();
    for (auto [di, ns] : nodes) {
        i64 cur_ans = 0;
        edge_sum += ns.size();
        while (it != nodes.end() && it -> first < di ) {
            for (auto u : it -> second) {
                i64 k = dfs2(dfs2, u, parent[u]);
                leave_sum += k;
                debug(di, u, k);
            }
            it = next(it);
        }
        cur_ans = (n - 1 - edge_sum + leave_sum);
        ans = min(ans, cur_ans);
        debug(di, edge_sum, leave_sum, cur_ans);
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}