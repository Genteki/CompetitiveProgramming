// g.cpp
#include <bits/stdc++.h>

using namespace std;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> l(n, 0), r(n, 1);
    vector d(n, vector<int>(n, 0));
    while(q--) {
        int i;
        char x;
        cin >> i >> x;
        --i;
        if (x == '+') {
            r[i]++;
        } else {
            if (r[i] - l[i] > 1) {
                l[i]++;
            }
        }
        for (int j = 0; j < n; ++j) {
            d[i][j] = max(d[i][j], r[i]-l[j]);
            d[j][i] = max(d[j][i], r[j]-l[i]);
        }
    }
    vector dp(1<<n, vector<int>(n, 1e9));
    fill(dp[0].begin(), dp[0].end(), 0);

    for (int i = 0; i < n; ++i) {
        dp[1<<i][i] = 0;
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int ed = 0; ed < n; ++ed) {
            if (!((1<<ed) & mask)) {
                int& nxt = dp[(1 << ed) | mask][ed];
                for (int j = 0; j < n; ++j) {
                    if ((1<<j)&mask) chmin(nxt, dp[mask][j] + d[j][ed]);
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        chmin(ans, dp[((1<<n)-1)][i] + r[i]);
    }
    cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}