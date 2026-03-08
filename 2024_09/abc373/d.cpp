// d.cpp

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
void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n, 0);
    vector g(n, vector<pair<i64, i64>>());
    for (;m--;) {
        i64 u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    } 
    vector<bool> fixed(n, false);
    bool begin = true;
    auto dfs = [&](auto& self, i64 u, bool begin = true) -> void {
        if (begin == true) {
            a[u] = 0;
            fixed[u] = true;
            begin = false;
        }
        for (auto &[v, w] : g[u]) {
            if (!fixed[v]) {
                a[v] = a[u] + w;
                fixed[v] = true;
                self(self, v, begin);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!fixed[i]) {
            dfs(dfs, i);
        }
    }
    debug(g);
    for (auto ai : a) cout << ai << " ";
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