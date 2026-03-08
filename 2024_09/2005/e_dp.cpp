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
const int N = 301;
const int L = 3e6 + 1;
const int INF = 0x3f3f3f3f;
typedef long long i64;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<i64> a(l);
    input(a);
    vector b(n, vector<i64>(m));
    for (auto& bi : b) {
        input(bi);
    }

    vector dp0(n + 1, vector<int>(m + 1, INF)),
        dp1(n + 1, vector<int>(m + 1, INF));
    vector<bool> viewed(L, false);
    vector<int> index(L, -1);
    for (int i = 0; i < l; ++i) {
        if (viewed[a[i]]) {
            l = i;
            break;
        }
        viewed[a[i]] = true;
        index[a[i]] = i;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int x = b[i][j];
            int ix = index[x];
            dp0[i][j] = min(dp0[i + 1][j], dp0[i][j + 1]);
            dp1[i][j] = min(dp1[i + 1][j], dp1[i][j + 1]);
            if (ix == -1) continue;
            if (dp0[i + 1][j + 1] - 1 == ix) {
                dp0[i][j] = ix;
            } else if (dp1[i + 1][j + 1] - 1 == ix) {
                dp1[i][j] = ix;
            } else if (ix % 2 == 0) {
                dp0[i][j] = min(dp0[i][j], ix);
            } else {
                dp1[i][j] = min(dp1[i][j], ix);
            }
        }
    }
    if (dp0[0][0] == 0)
        cout << "T";
    else
        cout << "N";
    cout << "\n";
    debug(dp0);
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