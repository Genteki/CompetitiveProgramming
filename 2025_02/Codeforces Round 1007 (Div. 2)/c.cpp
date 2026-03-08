// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, st, ed;
    cin >> n >> st >> ed;
    --st; --ed;
    vector g(n, vector<int>());
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u>> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> path;
    auto dfs = [&](this auto && self, int u, int p=-1) -> bool {
        if (u == ed) {path.push_back(u); return true;}
        for (auto v : g[u]) {
            if (v==p) continue;
            bool r = self(v, u);
            if (r) {
                path.push_back(u);
                return true;
            }
        }
        return false;
    };
    dfs(st);
    debug(path);
    reverse(path.begin(), path.end());
    vector<int> used(n, 0);
    for (auto pi : path) used[pi] = 1;
    vector<int> ans;
    vector<int> cur;
    auto dfs2 = [&](this auto&& self, int u, int p=-1) -> void {
        for (auto v : g[u]) {
            if (v == p or used[v] == 1) continue;
            self(v, u);
        }
        cur.push_back(u);
    };
    for (auto pi : path) {
        cur.clear();
        dfs2(pi);
        for (auto curi : cur) ans.push_back(curi);
    }
    for (auto ai : ans) cout << (ai+1) << " "; cout << endl;
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