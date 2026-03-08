// g.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    vector g(n, vector<int>());
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) roots.push_back(i);
        else { g[i].push_back(a[i]);
        g[a[i]].push_back(i);}
    }
    // if (roots.empty()) cout << -1 << endl;
    // find cyclex
    vector<int> viewed(n, 0);
    auto dfs = [&](this auto&& self, int u, int p=-1) -> bool {
        bool r = true;
        viewed[u] = true;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (viewed[v]) return false;
            r &= self(v, u);
            if (!r) return r;
        }
        return r;
    };
    for (int i = 0; i < n; ++i) {
        bool x;
        if (!viewed[i]) x = dfs(i, -1);
        if (!x) {
            cout << -1 << endl;
            return;
        } 
    }
    // build merge
    vector<pair<int,int>> ops;
    auto dfs2 = [&](this auto&& self, int u, int p=-1) -> void {
        for (auto v : g[u]) {
            if (v == p) continue;
            self(v, u);
        }
        if (p != -1) {
            ops.emplace_back(u, p);
        }
    };
    for (auto ri : roots) dfs2(ri);
    cout << ops.size() << endl;
    for (auto [u, v] : ops) cout << u << " " << v << endl;
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