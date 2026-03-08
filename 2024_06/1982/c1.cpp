#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f;  // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    i64 l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    input(a);
    vector<i64> prefix_sum(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            i64 range_sum = prefix_sum[i] - prefix_sum[j];
            if (range_sum >= l && range_sum <= r) {
                dp[i] = max(dp[i], dp[j] + 1);
            } else {
                dp[i] = dp[i-1];
            }
        }
    }

    cout << dp[n] << endl;
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