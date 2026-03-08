// e.cpp
// [graph_dp] [dijkstra]
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;
const i64 INF = LLONG_MAX;
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
void solve() {
    i64 n, m;
    i64 x;
    cin >> n >> m >> x;
    vector<vector<vector<i64>>> g(2, vector<vector<i64>>(n));
    for (i64 i = 0; i < m; ++i) {
        i64 u, v;
        cin >> u >> v;
        --u; --v;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }

    vector<array<i64, 2>> dp(n, {INF, INF});
    dp[0][0] = 0;
    priority_queue<array<i64, 3>, vector<array<i64,3>>, std::greater<>> pq;
    pq.push({0, 0, 0});
    vector<int> viewed(n*2, 0);
    while(!pq.empty()) {
        auto [d, u, p] = pq.top();
        pq.pop();
        
        if (viewed[n * p + u] == 1) continue;;
        viewed[n * p + u] = 1;
        debug(d, u, p);
        for (auto v : g[p][u]) {
            // if (dp[v][p] < INF) continue;
            if (chmin(dp[v][p], d + 1)) {
                pq.push({d + 1, v, p});
            }
        }
        if (chmin(dp[u][!p], d + x)) {
            pq.push({d+x, u, !p});
        }
    }
    debug(dp);
    cout << min(dp[n-1][0], dp[n-1][1]) ;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}