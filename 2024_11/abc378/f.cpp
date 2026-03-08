// f.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >>u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> deg(n, -1);
    for (int i = 0; i < n; ++i) {
        deg[i] = g[i].size();
    }
    vector<int> viewed(n, false);
    auto dfs = [&] (auto &&self, int u, int& cnt) -> void {
        debug(u);
        // if (deg[u] == 2) {
        //     ++cnt;
        //     return;
        // }
        viewed[u] = true;

        for (auto v : g[u]) {
            if (!viewed[v] && deg[v] == 3) {
                self(self, v, cnt);
            } else if (deg[v] == 2) {
                ++cnt;
            }
        }
    };
    vector<i64> cc;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 3 && !viewed[i]) {
            int cnt = 0;
            dfs(dfs, i, cnt);
            cc.push_back(cnt);
            debug(cc);
        }
    }
    i64 ans = 0;
    for (auto & ci : cc) {
        ans = ans + ci * (ci - 1) / 2; 
    }
    auto dfs2 = [&](auto&& self, int u, int& cnt) -> void {
        debug(u);
        ++cnt;
        viewed[u] = true;
        for (auto v : g[u]) {
            if (!viewed[v] && deg[v] == 2) {
                self(self, v, cnt);
            }
        }
    };
    cc.clear();
    memset(viewed.data(), 0, n * sizeof(viewed[0]));
    // for (int i = 0; i < n; ++i) {
    //     if (deg[i] == 2 && !viewed[i]) {
    //         int cnt = 0;
    //         dfs2(dfs2, i, cnt);
    //         cc.push_back(cnt);
    //         debug(cc);
    //     }
    // }
    // for (auto& ci : cc) {
    //     ans = ans + ci - 1;
    // }
    cout << ans;
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