// atcoder_sushi.cpp
// https://atcoder.jp/contests/dp/tasks/dp_j
// DP
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
// expected value dp (expectation)
// dp[i][j][k] + 1
//     = (n-i-j-k)/n * dp[i][j][k]
//     + i/n * dp[i-1][j][k] + j/n * dp[i+1][j-1][k]
//     + k/n * dp[i][j+1][k-1]
typedef long long i64;
const int inf = 0x3f3f3f3f; 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n; cin >> n;
    int nx = 0, ny = 0, nz = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        switch (a) {
        case 1:
            ++nx;
            break;
        case 2:
            ++ny;
            break;
        case 3:
            ++nz;
            break;
        }
    }
    double nf = n;

    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1, 0.0f)));
    dp[0][0][0] = 0;
    for (int k = 0; k <= n; ++k) {
        for (int j = 0; j <= n; ++j) {
            for (int i = 0; i <= n; ++i) {
                debug(i, j, k);
                int a = i + j + k;
                if (a == 0 || a > n) continue;
                if (i) dp[i][j][k] += dp[i - 1][j][k] * i;
                if (j) dp[i][j][k] += dp[i + 1][j - 1][k] * j;
                if (k) dp[i][j][k] += dp[i][j + 1][k - 1] * k;
                dp[i][j][k] = (dp[i][j][k] + n) / (a);
            }
        }
    }
    // cout << nx << ny << nz << endl;
    cout << setprecision(10) << dp[nx][ny][nz] << endl;
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