// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    if (*min_element(a.begin(), a.end()) != 0) {
        cout << 1 << endl;
        cout << "1 " << n << endl;
        return;
    }
    int l = 1e7, r = -1, cnt = 0;
    for (int i = 0; i < n ; ++i) {
        if (a[i] == 0) {
            chmin(l, i);
            chmax(r, i);
            ++cnt;
        }
    }
    debug(l, r);
    if (cnt == 1 and l != 0) {
        cout << 2 << endl;
        cout << l << " " << (l + 1) << endl;
        cout << "1 " << (n - 1) << endl;
        return;
    } else if (cnt == 1) {
        cout << 2 << endl;
        cout << "1 2" << endl;
        cout << "1 " << (n - 1) << endl;
        return;
    }
    if (l == 0 and r == n-1) {
        cout << 3 << endl;
        cout << "1 2" << endl;
        cout << "2 " << (n-1) << endl;
        cout << "1 2" << endl;
    } else {
        cout << 2 << endl;
        cout << l+1 << " " << r+1 << endl;
        cout << 1 << " " << (n-(r-l)) << endl;
    }

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