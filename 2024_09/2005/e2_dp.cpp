// e2_dp.cpp

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
const int N = 1501;
const int L = N * N;
const int INF = 0x3f3f3f3f;
typedef long long i64;
vector dp(N, vector<int>(N, INF));
vector winner(N, vector<int>(N, true));
vector<int> a(N);
vector b(N, vector<int>(N));

void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    for (int i = 0; i < l; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i <= n; ++i) {
        memset(dp[i].data(), 0x3f, sizeof(dp[i]) * sizeof(int));
        winner[i].assign(m + 1, true);
    }
    vector<int> index(n * m + 1, -1);
    for (int i = 0; i < l; ++i) {
        if (index[a[i]] != -1) {
            l = i;
            break;
        }
        index[a[i]] = i;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int x = b[i][j];
            int ix = index[x];
            if (dp[i + 1][j] > dp[i][j + 1]) {
                dp[i][j] = dp[i][j + 1];
                winner[i][j] = winner[i][j + 1];
            } else if (dp[i + 1][j] < dp[i][j + 1]) {
                dp[i][j] = dp[i + 1][j];
                winner[i][j] = winner[i + 1][j];
            } else {
                dp[i][j] = dp[i + 1][j];
                if (winner[i + 1][j] != winner[i][j + 1]) {
                    winner[i][j] = dp[i][j] % 2;
                } else {
                    winner[i][j] = winner[i + 1][j];
                }
            }
            if (ix == -1 || ix >= dp[i][j]) continue;
            if (ix + 1 == dp[i + 1][j + 1]) {
                dp[i][j] = ix;
                winner[i][j] = winner[i + 1][j + 1];
            } else {
                dp[i][j] = ix;
                winner[i][j] = ix % 2;
            }
        }
    }

    if (winner[0][0] == false)
        cout << "T\n";
    else
        cout << "N\n";
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}