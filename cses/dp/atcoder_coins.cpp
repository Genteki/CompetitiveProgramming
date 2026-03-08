// Coins
// https://atcoder.jp/contests/dp/tasks/dp_i
// DP

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<double> a(n);
    input(a);
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0f));
    dp[0][0] = 1.0f;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] * (1.0f - a[i-1]);
            } else {
                dp[i][j] = dp[i-1][j] * (1.0f - a[i-1]) + dp[i-1][j-1] * a[i-1];
            }
        }
    }
    double ans = 0.f;
    for (int i = n/2+1; i <= n; ++i) {
        ans += dp[n][i];
    }
    cout << setprecision(9);
    cout << ans << endl;
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