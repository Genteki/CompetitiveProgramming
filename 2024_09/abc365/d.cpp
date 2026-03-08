// d.cpp

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    map<char, int> mp({{'S', 0}, {'R', 1}, {'P', 2}});
    for (int i = 0; i < n; ++i) {
        int x = mp[s[i]];
        auto & tgt = dp[i + 1][(x + 1) % 3] ;
        tgt = max(dp[i][x] + 1, dp[i][(x + 2) % 3 ] + 1);
        // tgt = max(dp[i][(x+1)%3], tgt);
        dp[i + 1][x] = max(dp[i][(x + 1) % 3], dp[i][(x + 2) % 3]);
    }
    debug(dp);
    cout << *max_element(all(dp[n]));
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