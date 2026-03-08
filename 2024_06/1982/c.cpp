#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    i64 l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    input(a);
    vector<i64> prefix_sum(n+1, 0);
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + a[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        int high = i, low = 0;
        int g = -1;
        // cout << (prefix_sum[i]) << l << endl;
        if (prefix_sum[i] == l) {
            g = 0;
        } else if (prefix_sum[i] > l) {
            while (high - low > 1) {
                int mid = (high + low) / 2;
                i64 range_sum = prefix_sum[i] - prefix_sum[mid];
                if (range_sum == l) {
                    low = mid;
                    break;
                } else if (range_sum > l) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            if (prefix_sum[i] - prefix_sum[low] <= r) {
                g = low;
            }
        }
        if (g == -1) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = max(dp[i-1], dp[g] + 1);
        }
    }
    // for (int dpi:dp) cout << dpi <<  " ";
    // cout << endl;
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