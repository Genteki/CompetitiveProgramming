// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const int N = 3000;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    int ans = 0;
    vector dp(n+1, vector<int>(n+1, 1));
    for (int d = 1; d <= n; ++d) {
        for (int i = 0; i < n; ++i) {
            if (i + d < n) {
                if (a[i] == a[i+d]) {
                    dp[d][i+d] = dp[d][i] + 1;
                } else {
                    dp[d][i+d] = 1;
                }
            }
        }
        ans = max(ans, *max_element(dp[d].begin(), dp[d].end()));
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}