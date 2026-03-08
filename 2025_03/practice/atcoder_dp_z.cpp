#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;
const i64 inf = LLONG_MAX;
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
void solve() {
    i64 n, c;
    cin >> n >> c;
    vector<i64> h(n);
    for (auto & hi : h) cin >> hi;
    vector<i64> dp(n, inf); 
    dp[0] = 0;
    // dp[i] 
    //  = min_j {dp[j] + (h[i] - h[j])^2 + C}
    //  = min_j {dp[j] + h[j]^2 - 2h[i]h[j]} + h[i]^2 + C
    // k = -2h[j], b = dp[j] + h[j]^2
    deque<int> dq;
    dq.push_back(0);
    auto intersect = [&](int i, int j) -> double {
        return double(dp[i] - dp[j] + h[i]*h[i] - h[j]*h[j]) / double(h[i] - h[j]) / 2; 
    };
    auto f = [&](int i, int j) -> i64 {
        return dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
    };
    for (int i = 1; i < n; ++i) {
        while(dq.size() >= 2 && f(i, dq[0]) >= f(i, dq[1])) {
            dq.pop_front();
        }
        dp[i] = f(i, dq[0]);
        while(dq.size() >= 2 && intersect(i, dq.rbegin()[0]) <= intersect(i, dq.rbegin()[1])) {
            dq.pop_back();
        }
        dq.push_back(i);
        debug(dq);
    }
    debug(dp);
    cout << dp[n-1] << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}