// abc320b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
const i64 inf = 1e18;
void solve() {
    i64 n, h;
    cin >> n >> h;
    vector<i64> x(n), d(n), f(n,0), p(n,0);
    for (i64 i = 0; i < n; ++i) cin >> x[i];
    d[0] = x[0];
    for (i64 i = 1; i < n; ++i) d[i] = x[i] - x[i-1];
    for (i64 i = 0; i < n-1; ++i) cin >> p[i] >> f[i];
    vector dp(n+1, vector(h+1, vector<i64>(h+1, inf)));
    for (i64 i = 0; i <= h; ++i) {
        for (i64 j = 0; j <=h; ++j) {
            dp[0][i][j] = 0;
        }
    }
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j <= h; ++j) {
            for (i64 k = 0; k <= h; ++k) {
                if (dp[i][j][k]==inf) continue;
                if (j-d[i]>=0 and k+d[i]<=h) {
                    chmin(dp[i+1][j-d[i]][k+d[i]], dp[i][j][k]);
                }
                if (j-d[i]>=0 and k+d[i]<=h){
                    chmin(dp[i+1][min(h, j-d[i]+f[i])][k+d[i]], dp[i][j][k]+p[i]);
                    chmin(dp[i+1][h, j-d[i]][max(0LL, k+d[i]-f[i])], dp[i][j][k]+p[i]);
                    if (k+d[i]==h) {
                        for (int l = 0; k+d[i]-f[i]+l <= h; ++l) {
                    // chmin(dp[i+1][h, j-d[i]][max(0LL, k+d[i]-f[i]+l)], dp[i][j][k]+p[i]);
                            
                        }
                    }
                }
            } 
        }
    }
    debug(dp[1]);
    i64 ans = inf;
    for (i64 i = 0; i <= h; ++i) {
        chmin(ans, dp[n][i][i]);
    }

    if (ans < inf)cout << ans;
    else cout << -1;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}