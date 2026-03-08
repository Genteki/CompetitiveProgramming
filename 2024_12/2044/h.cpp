// h.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<i64>> a(n, vector<i64>(n));
    for (auto&mi : a) for (auto &mii : mi) cin >> mii;
    auto b = a, c= a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = i * a[i][j];
            c[i][j] = j * a[i][j];
        }
    }
    vector<vector<i64>> psa(n + 1, vector<i64>(n + 1, 0)),
        psb(n + 1, vector<i64>(n + 1, 0)),
        psc(n + 1, vector<i64>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            psa[i + 1][j + 1] = psa[i + 1][j] + a[i][j];
            psb[i + 1][j + 1] = psb[i + 1][j] + b[i][j];
            psc[i + 1][j + 1] = psc[i + 1][j] + c[i][j];
        }
        for (int j = 0; j < n; ++j) {
            psa[i + 1][j + 1] += psa[i][j + 1];
            psb[i + 1][j + 1] += psb[i][j + 1];
            psc[i + 1][j + 1] += psc[i][j + 1];
        }
    }
    debug(psa);
    while(q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        i64 sa = psa[x2 + 1][y2 + 1] + psa[x1][y1] - psa[x1][y2+1] - psa[x2+1][y1];
        i64 sb = psb[x2 + 1][y2 + 1] + psb[x1][y1] - psb[x1][y2+1] - psb[x2+1][y1];
        i64 sc = psc[x2 + 1][y2 + 1] + psc[x1][y1] - psc[x1][y2+1] - psc[x2+1][y1];
        cout << ( (y2-y1+1) * sb + sc + (-x1 * (y2-y1+1) - y1 + 1) * sa) << " ";
    }
    cout << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}