// lcs
// https://atcoder.jp/contests/dp/tasks/dp_f
// DP

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int max_len = 0, max_i;
    string ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i - 1][j]> dp[i - 1][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else if (dp[i][j - 1]> dp[i - 1][j - 1]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j]++;
                }
            }
        }
    }

    // for (auto dpi : dp) {
    //     for (auto dpii : dpi) {
    //         cout << dpii << " ";
    //     } cout << endl;
    // }

    auto dfs = [&](auto && self, int i, int j) -> void {
        if (i == 0 || j == 0) return;
        if (dp[i][j] == dp[i-1][j]) {
            self(self, i-1, j);
        } else if (dp[i][j] == dp[i][j-1]) {
            self(self, i, j-1);
        } else if (dp[i-1][j-1] == dp[i][j]) {
            self(self, i-1, j-1);
        } else {
            self(self, i-1, j-1);
            cout << s[i-1];
        }
    };
    dfs(dfs, n, m);
    cout << endl;
    
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