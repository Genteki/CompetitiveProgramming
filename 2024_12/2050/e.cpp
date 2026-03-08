// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
typedef long long i64;
const int inf = 1e9;
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, inf));
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) {
                if (a[i] == c[i + j]) {
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
                } else {
                    dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
                }
            }
            if (j < m) {
                if (b[j] == c[i + j]) {
                    dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
                } else {
                    dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
                }
            }
            
        }
    }
    cout << dp[n][m] << endl;
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