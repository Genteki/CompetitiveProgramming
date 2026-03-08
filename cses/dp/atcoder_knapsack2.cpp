// atcoder_knapsack2.cpp
// https://atcoder.jp/contests/dp/tasks/dp_e
// dp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n; i64 w;
    cin >> n >> w;
    vector<i64> weight(n), value(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    int M = 100001;
    vector<i64> dp(100001, inf);
    dp[0] = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int mj = M;
        // for (int j = 0; j < M; ++j) {
        //     if (dp[j] == inf) {mj = j-1; break;}
        // }
        // cout << mj << endl;
        for (int j = min(M - (int)value[i], mj); j >= 0; --j) {
            if (dp[j]+weight[i] <= w) {
                // cout << (j + value[i]) << " "
                //      << min(dp[j + value[i]], dp[j] + weight[i]) << endl;
                dp[j+value[i]] = min(dp[j+value[i]], dp[j]+weight[i]);
            }
        }
        // if ()
    }
    for (int i = M-1; i >= 0; --i) {
        if (dp[i] <= w) {
            // cout << i << endl;
            ans = i;
            break;
        }
    }
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