// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;
const int INF = 0x3f3f3f3f;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int N = x + 1;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(N, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int salt = a[i], sweet = b[i];
        for (int j = 0; j < i + 1; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
                if(k >= salt) dp[i+1][j+1][k] = min(dp[i][j][k-salt]+sweet, dp[i+1][j+1][k]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= x; ++k) {
            if (dp[n][j][k] <= y) {
                ans = max(j, ans);
            }
        }
    }

    cout << min(n, (ans + 1)) << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}