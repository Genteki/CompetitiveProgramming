// cf2019d.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    int l=n, r=-1;
    vector<int> x(n+1, n), y(n+1, -1);
    for (int i = 0; i < n; ++i) {
        chmin(x[a[i]], i);
        chmax(y[a[i]], i);
    }
    int ans = 1e7;
    int maxr=n-1, minl=0;
    for (int i = 1; i < n; ++i) {
        chmin(l, x[i]);
        chmax(r, y[i]);
        chmin(maxr, r + (i-(r-l+1)));
        chmax(minl, l - (i-(r-l+1)));
        if(x[i] <= y[i]) chmin(ans, maxr-minl+1);
        if (r-l >= i) {
            debug(l, r, i);
            cout << 0 << endl;
            return;
        }
    }
    cout << (maxr-minl+1) << endl;
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