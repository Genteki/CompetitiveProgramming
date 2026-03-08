// NOI_sg_Feast.cpp
// [Aliens Trick], [Lagrangian Relaxation]

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

void solve() {
    i64 n,k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;

    using pii = pair<i64,i64>;
    vector<array<i64,2>> dp(n+1);
    vector<array<i64,2>> cnt(n+1);
    auto check = [&](i64 lambda) -> pii {
        /*
            dp[i+1][0] = max(dp[i][0], dp[i][1]);
            dp[i+1][1] = max(dp[i][0] + a[i] - lambda, dp[i][1] + a[i])
        */
        dp[0] = {0, -lambda};
        cnt[0] = {0, 1};
        for (int i = 0; i < n; ++i) {
            // dp[i+1][0]
            if (dp[i][0] > dp[i][1]) {
                dp[i+1][0] = dp[i][0];
                cnt[i+1][0] = cnt[i][0];
            } else {
                dp[i + 1][0] = dp[i][1];
                cnt[i + 1][0] = cnt[i][1];
            }
            // dp[i+1][1]
            if (dp[i][0] + a[i] - lambda > dp[i][1] + a[i]) {
                dp[i + 1][1] = dp[i][0] + a[i] - lambda;
                cnt[i+1][1] = cnt[i][0] + 1; 
            } else {
                dp[i + 1][1] = dp[i][1] + a[i];
                cnt[i+1][1] = cnt[i][1];
            }
        }
        return (dp[n][0] > dp[n][1] ? (pii){dp[n][0], cnt[n][0]}
                                    : (pii){dp[n][1], cnt[n][1]});
    };

    i64 low = -1, high = 1e18;
    while(high > low + 1) {
        i64 mid = (high + low + 1) / 2;
        auto [val, c] = check(mid);
        if (c <= k) high = mid;
        else low = mid;
    }

    auto [ans, c] = check(high);
    cout << (ans + c * high);
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}