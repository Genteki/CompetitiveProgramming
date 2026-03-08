// 1661f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    i64 m;
    cin >> m;
    vector<i64> dp(n+1, LLONG_MAX);
    dp[0] = 0;
    /*
        dp[i] = min{dp[j] + (dp[i]-dp[j])}
    */
    
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}