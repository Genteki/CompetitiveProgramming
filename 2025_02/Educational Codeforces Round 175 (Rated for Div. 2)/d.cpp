#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;
const i64 mod = 998244353;

void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64>> g(n);
    vector<i64> p(n, -1);
    for (i64 i = 1; i < n; ++i) {
        i64 x;
        cin >> x;
        --x;
        g[i].push_back(x);
        g[x].push_back(i);
        p[i] = x;
    }
    vector<i64> dp(n, 0);
    vector<i64> s(n + 5, 0);
    dp[0] = 1;
    s[0] = 2;
    queue<pair<i64, i64>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (v == p[u]) continue;
            dp[v] = (s[d] - dp[u]) % mod;
            s[d + 1] += dp[v];
            s[d + 1] %= mod;
            q.emplace(v, d + 1);
        }
    }
    debug(p);
    i64 ans = 0;
    for (auto ai : dp) ans = (ans + ai) % mod;
    cout << (ans+mod)%mod << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}