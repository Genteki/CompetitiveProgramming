// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 mod = 998244353;

const int inf = 0x3f3f3f3f;  // memset(a, 0x3f, sizeof(a))

void solve() {
    int k;
    cin >> k;
    vector<int> c(26);
    input(c);
    vector<vector<i64>> dp(27, vector<i64>(k + 1, 0));
    dp[0][0] = 1;  // One way to make an empty string
    vector<vector<i64>> comb(k + 1, vector<i64>(k + 1, 0));
    for (int i = 0; i <= k; ++i) {
        comb[i][1] = i;
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 2; j < i; ++j) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }

    int result = 0;

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= min(k - j, c[i]); ++l) {
                dp[i + 1][j + l] += (dp[i][j] * comb[j + l][l]);
                dp[i + 1][j + l] %= mod;
            }
        }
        // for (int j = 0; j <= k; ++j) {
        //     cout << dp[i+1][j] << " ";
        // }
        cout << endl;
    }

    for (int i = 1; i <= k; ++i) {
        result = (result + dp[26][i]) % mod;
    }
    cout << result << endl;
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