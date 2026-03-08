// d.cpp
#include <bits/stdc++.h>

using namespace std;
bool chmin(int& a, int b) { return b < a ? a = b, true : false; }
bool chmax(int& a, int b) { return b > a ? a = b, true : false; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;
    
    vector dp(2, vector<int>(n, 1e6));
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[1][1] = 2 + (a[0] != a[1]);
    for (int i = 1; i < n; ++i) {
        chmin(dp[0][i], dp[0][i - 1] + (a[i] != a[i - 1]));
        if (i >= 2) chmin(dp[1][i], dp[0][i - 2] + 2 + (a[i - 2] != a[i]));
        if (i >= 2) chmin(dp[0][i], dp[1][i - 1] + (a[i - 2] != a[i]));
        if (i >= 3) chmin(dp[1][i], dp[1][i - 2] + 2 + (a[i - 3] != a[i]));
    }
    cout << min(dp[0][n - 1], dp[1][n - 1]) << endl;
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