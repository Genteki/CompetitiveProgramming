// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> m(2, vector<char>(n));
    for (auto & mi: m ) {
        for (auto & mii : mi) {
            cin >> mii;
        }
    }
    vector<int> dp(n + 1, 0);
    auto f1 = [&](int i) -> int {
        int p = 0;
        if (m[0][i] == 'A') ++p;
        if (m[1][i] == 'A') ++p;
        if (m[1][i + 1] == 'A') ++p;
        return int(p >= 2);
    };
    auto f2 = [&](int i) -> int {
        int p = 0;
        if (m[0][i] == 'A') ++p;
        if (m[1][i] == 'A') ++p;
        if (m[0][i + 1] == 'A') ++p;
        return int(p >= 2);
    };
    auto f3 = [&](int i) -> int {
        int p = 0;
        if (m[0][i] == 'A') ++p;
        if (m[1][i + 1] == 'A') ++p;
        if (m[0][i + 1] == 'A') ++p;
        return int(p >= 2);
    };
    auto f5 = [&](int i) -> int {
        int p = 0;
        if (m[0][i] == 'A') ++p;
        if (m[1][i] == 'A') ++p;
        if (m[1][i - 1] == 'A') ++p;
        return int(p >= 2);
    };
    auto f4 = [&](int i, int j) -> int {
        int ans = 0;
        int p = 0;
        if (m[0][i] == 'A') ++p;
        if (m[0][i + 1] == 'A') ++p;
        if (m[0][i + 2] == 'A') ++p;
        ans += (p >= 2);
        p = 0;
        if (m[1][j] == 'A') ++p;
        if (m[1][j + 1] == 'A') ++p;
        if (m[1][j + 2] == 'A') ++p;
        ans += (p >= 2);
        return ans;
    };

    for (int i = 0 ; i < n ; ++ i) {
        if ( i % 3 == 0) {
            if (i + 1 <= n) dp[i + 1] = max(dp[i + 1], f1(i) + dp[i]);
            if (i + 2 <= n) dp[i + 2] = max(dp[i + 2], f2(i) + dp[i]);
            if (i + 3 <= n) dp[i + 3] = max(dp[i + 3], f4(i, i) + dp[i]);
        } else if (i % 3 == 1) {
            if (i + 2 <= n) dp[i + 2] = max(dp[i + 2], f3(i) + dp[i]);
            if (i + 4 <= n) dp[i + 3] = max(dp[i + 3], f4(i, i + 1) + dp[i]);
        } else {
            if (i + 1 <= n) dp[i + 1] = max(dp[i + 1], f5(i) + dp[i]);
            if (i + 3 <= n) dp[i + 3] = max(dp[i + 3], f4(i, i - 1) + dp[i]);
        }
    }
    debug(f5(5) + dp[5]);
    cout << dp[n] << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}