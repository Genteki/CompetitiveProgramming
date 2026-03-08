// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < n-1; ++i) {
        i64 u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    i64 leaves = 0;
    vector<i64> depth(n, 1e7);
    // direct win
    for (i64 i = 0; i < n; ++i) {
        if (g[i].size()==1) ++leaves;
    }
    i64 ans = leaves * (n-leaves);
    // parent(depth_q) == 1 and depth_p >= 2
    queue<pair<i64,i64>> q;
    for (i64 i = 0; i < n; ++i) {
        if (g[i].size() == 1){
            depth[i] = 0;
            q.emplace(i, 1);
        }
    }
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        for (auto v : g[u]) {
            if(chmin(depth[v], d)) {
                q.emplace(v, d+1);
            }
        }
    }
    i64 cnt_dep = 0;
    for (i64 i = 0; i < n; ++i) {
        if (depth[i] >= 2) {
            ++cnt_dep;
        }
    }
    vector<i64> good_q (n, 0);
    for (i64 i = 0; i < n; ++i) {
        if (g[i].size()==1) {
            good_q[g[i][0]] = 1;
        }
    }
    for (i64 i = 0; i < n; ++i) {
        if (good_q[i]) {
            i64 x = 0;
            for (i64 v : g[i]) {
                if (depth[v] >= 1) ++x;
            }
            if(x>0) ans += ((x-1) * cnt_dep);
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}