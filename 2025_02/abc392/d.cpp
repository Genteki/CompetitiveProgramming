// d.cpp
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef long double fp64;
const int N = 1e5+1;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> k(n);
    vector a(n, vector<i64>(N,0));
    vector b(n, set<int>());
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            int x;
            cin >> x;
            b[i].insert(x);
            a[i][x]+=1;
        }
    }
    sort(ord.begin(), ord.end(), [&](int lhs, int rhs) ->bool{return b[lhs].size() < b[rhs].size();});
    debug(b);
    fp64 ans = 0;
    for (int ii = 0; ii < n; ++ii) {
        for (int jj = ii + 1; jj < n; ++jj) {
            int i = ord[ii], j = ord[jj];
            i64 cur_ans = 0;
            for (auto x : b[i]) {
                cur_ans += (a[i][x] * a[j][x]);
            }
            ans = max(ans, (fp64)cur_ans / k[i] / k[j]);
        }
    }
    cout << fixed << setprecision(12) << ans;
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