// b.cpp
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
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    set<int> b;
    int ans = 1;
    int mex=0;
    auto getmex = [&] () {
        while(b.find(mex) != b.end()) {
            ++mex;
        }
    };
    ans = 0;
    int idx0 = 1e9;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            ++ans;
        } else {
            idx0 = min(idx0, i);
        }
    }
    if (ans == n) {
        cout << ans << endl;
        return;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != 0) {
            getmex();
            if (a[i] >= mex)
                b.insert(a[i]);
            else {
                cout << ans << endl;
                return;
            }
        } else if (i == idx0) {
            b.insert(0);
        }
    }
    cout << (ans+1) << endl;
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