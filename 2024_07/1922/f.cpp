#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
const int inf = 0x3f3f3f3f;

typedef long long i64;

void solve() {
    int n, x;
    cin >> n >> x;
    // cout << 
    vector<int> a(n);
    input(a);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(x+1, inf)));
    vector<vector<vector<int>>> dp2(n, vector<vector<int>>(n, vector<int>(x+1, inf)));
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = 0;
        for (int j = 1; j <= x; ++j) {
            dp[i][i][j] = (a[i] == j ? 0 : 1);
            dp2[i][i][j] = (a[i] == j ? 1 : 0);
        }
    }

    for (int len = 1; len < n; ++len) {
        for (int l = 0; l < n-len; ++l) {
            int r = l + len;
            // if (r > n) break;
            for (int k = 1; k <= x; ++k) {
                int& tar = dp2[l][r][k];
                for (int m = l; m < r; ++m) {
                    tar = min(tar, dp2[l][m][k] + dp2[m+1][r][k]);
                }
            }
            int q = *min_element(all(dp2[l][r]));
            for (int k = 1; k <= x; ++k) {
                dp2[l][r][k] = min(q+1, dp2[l][r][k]);
            }
        } 
    }
    
    for (int len = 1; len < n; ++len) {
        for (int l = 0; l < n-len; ++l) {
            int r = l + len;
            for (int k = 1; k <= x; ++k) {
                int& tar = dp[l][r][k];
                tar = dp2[l][r][k] + 1;
                for (int m = l; m < r; ++m) {
                    tar = min(tar, dp[l][m][k] + dp[m+1][r][k]);
                }
            }
        }
    }
    // for(auto ai : dp2[0][n-1]) cout << ai << " "; cout << endl;
    // for(auto ai : dp[0][n-1]) cout << ai << " "; cout << endl;
    // for (int i = 4; i < n; ++i) {
    //     cout << dp2[4][i][2] << " ";
    // } cout << endl;

    cout << *min_element(all(dp[0][n-1])) << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}