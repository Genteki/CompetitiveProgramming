// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);

    vector<vector<i64>> dp(n + 1, vector<i64>(2, 0));
    dp[0][1] = INT_MIN;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        dp[i + 1][0] = max(dp[i][1] + 2 * a[i], dp[i+1][0]);
        dp[i + 1][1] = max(dp[i][0] + a[i], dp[i+1][1]);
    }
    cout << (*max_element(all(dp[n])));
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}