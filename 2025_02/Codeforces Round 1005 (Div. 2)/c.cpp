// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    vector<i64> b;
    int idx = 0;
    while(idx < n) {
        int j = 0;
        i64 s = 0;
        while (idx+j < n and a[idx+j]*a[idx] > 0) {
            s += a[idx+j];
            ++j;
        }
        idx += j;
        b.push_back(s);
    }
    n = b.size();
    vector<i64> pos(n, 0), neg(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (i) pos[i] = pos[i-1];
        if (b[i]>0) pos[i]+=b[i];
    }
    for (int i = n-1; i>=0; --i) {
        if (i != n-1) neg[i] = neg[i+1];
        if (b[i]<0) neg[i] -= b[i];
    }
    i64 ans = 0;
    for (int i = -1; i < n; ++i) {
        i64 cur = 0;
        if (i >= 0) cur += pos[i];
        if (i+1 < n) cur += neg[i+1];
        ans = max(ans, cur);
    }
    cout << ans << endl;
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