#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
struct comp { 
    bool operator()(int a, int b) const { return a < b; } 
};
inline bool chmin(i64& x, i64 y) { return x > y ? x = y, true : false; }
void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector<pair<int,int>>()), g_(n, vector<pair<int,int>>());
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        g[u].emplace_back(v, c);
        g_[v].emplace_back(u, c);
    }
    vector<i64> d1(n, 1e18), dn(n, 1e18);
    auto comp = [&](const pair<i64, int>& a, const pair<i64,int>& b) -> bool {return a.first > b.first;};
    priority_queue<pair<i64,int>, vector<pair<i64, int>>, decltype(comp)> pq(comp);
    d1[0] = 0; dn[n-1]= 0;
    pq.emplace(0, 0);
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d1[u] < d) continue;
        for (auto [v, l] : g[u]) {
            if (chmin(d1[v], l + d)) {
                pq.emplace(d1[v], v);
            }
        }
    }
    debug(d1);
    pq.emplace(0, n-1);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dn[u] < d) continue;
        for (auto [v, l] : g_[u]) {
            if (chmin(dn[v], l + d)) {
                pq.emplace(dn[v], v);
            }
        }
    }
    i64 ans = LLONG_MAX;
    for (int u = 0; u < n; ++u) {
        for (auto [v, c] : g[u]) {
            chmin(ans, d1[u] + dn[v] + c / 2);
        }
    }
    debug(dn);
    cout << ans << endl;
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