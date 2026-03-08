// https://atcoder.jp/contests/dp/tasks/dp_d
// DP

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, w;
    cin >> n >> w;
    vector<i64> weight(n), value(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    vector<i64> dp(w+1, 0);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = w; j >= weight[i]; --j) {
            // if (dp[j-weight[i]] == -1) break;
                dp[j] =  max(dp[j - weight[i]] + value[i], dp[j]);
        }
    }
    i64 ans = *max_element(all(dp));
    // for (auto dpi : dp) cout << dpi << " "; cout << endl;
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