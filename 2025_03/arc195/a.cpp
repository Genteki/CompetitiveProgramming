#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto & ai : a) cin >> ai;
    for (auto & bi : b) cin >> bi;
    vector<int> mp(m+1);
    int idx = 0;
    map<int, vector<int>> mpa;
    for (int i = 0; i < n; ++i) {
        mpa[a[i]].push_back(i);
        if (idx < m and a[i] == b[idx]) {
            mp[idx] = i;
            ++idx;
        }
    }
    if (idx < m) {
        cout << "No" << endl;
        return;
    }
    mp[m] = n;
    debug(mp);
    for (int i = m-1; i >= 0; --i) {
        int l = mp[i];
        int r = mp[i+1];
        vector<int> &la = mpa[b[i]];
        auto it = upper_bound(la.begin(), la.end(), l);
        if (it != la.end() and *it < r) {
            debug(i, *it);
            debug(la, r);
            cout << "Yes";
            return;
        }
    }
    cout << "No" << endl;

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}