// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i] + 1;
        if (i >= 1 && s[i] == '0' && s[i-1] == '0') {
            dp[i+1] = min(dp[i-1] + 1, dp[i+1]);
        }
    }
    cout << dp[n];
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