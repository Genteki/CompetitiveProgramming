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
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    input(a);
    vector g(n, vector<pair<i64,i64>>());
    for (; m--;) {
        i64 u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<i64> d(n, LONG_MAX);
    vector<bool> used(n, false);
    priority_queue<
        pair<i64,i64>, vector<pair<i64,i64>>, greater<pair<i64,i64>>
    > pq;
    pq.emplace(0LL, 0);
    while(!pq.empty()) {
        auto [l, u] = pq.top();
        l+=a[u];
        pq.pop();
        if (used[u]) continue;
        debug(u);
        used[u] = true;
        for (auto [v, wv] : g[u]) {
            if (!used[v]) {
                if (wv + l < d[v]) {
                    d[v] = wv + l;
                    pq.emplace(d[v], v);
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) cout << (d[i]+a[i]) << " ";

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