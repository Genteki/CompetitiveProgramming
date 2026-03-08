// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    --s1; --s2;
    int m1, m2;
    cin >> m1;
    vector g1(n, vector<int>()), g2(n, vector<int>());
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    cin >> m2;
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    debug(g1);
    debug(g2);
    vector<int> t;
    auto check = [&](int i) -> bool {
        for(int j1 = 0; j1 < g1[i].size(); ++j1) {
            for(int j2 = 0; j2 < g2[i].size(); ++j2) {
                if (g1[i][j1] == g2[i][j2]) {
                    debug(i, j1, j2);
                    return true;
                }
            }
        }
        return false;
    };
    for (int i = 0; i < n; ++i) {
        if (check(i)) {
            t.push_back(i);
        }
    }
    if (t.size() == 0) {
        cout << -1 << endl;
        return;
    }
    vector distance(n, vector<int>(n, 1e9)), viewed(n, vector<int>(n,0));
    distance[s1][s2] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> ,
                   greater<>> pq;
    pq.emplace(0, s1, s2);
    
    while(!pq.empty()) {
        auto [d, u1, u2] = pq.top();
        pq.pop();
        if (viewed[u1][u2]) continue;
        viewed[u1][u2] = 1;

        for (auto v1 : g1[u1]) {
            for (auto v2 : g2[u2]) {
                if (d + abs(v1-v2) < distance[v1][v2]) {
                    distance[v1][v2] = d + abs(v1-v2);
                    pq.emplace(distance[v1][v2], v1, v2);
                }
            }
        }
    }
    i64 ans = 1e9;
    for (auto x : t) {
        if (distance[x][x] < 1e9) {
            ans = min<i64>(ans, distance[x][x]);
        }
    }
    debug(t);
    // debug(distance);
    if (ans < 1e9) cout << ans << endl;
    else cout << -1 << endl;
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