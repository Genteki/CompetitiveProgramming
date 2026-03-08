// 933a.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector dp(n + 1, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i+1][i+1] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                chmax(dp[i+1][i+1], dp[j+1][j+1] + 1);
            }
        }
    }

    
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