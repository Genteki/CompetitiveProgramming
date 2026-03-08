// f1.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> a(1, 0), b(1, 0);
    char last = s[0];
    if (s[0] != t[0]) a.push_back(0);
    for (auto si : s) {
        if (si == last) {
            a.back()++;
        } else {
            a.push_back(1);
        }
        last = si;
    }
    a.push_back(0);
    last = t[0];
    for (auto ti : t) {
        if (ti == last) {
            b.back()++;
        } else {
            b.push_back(1);
        }
        last = ti;
    }
    i64 is=0, it=0;
    i64 tmp = a[0];
    i64 ans = 0;
    int ck = 0;
    for (auto si : s) {
        ck += (si == '1');
    }
    for (auto ti : t) {
        ck -= (ti == '1');
    }
    if (ck != 0) {
        cout << -1 << endl;
        return;
    }
    while(it < b.size() and is < a.size()-2) {
        if(tmp == b[it]) {
            ++it;
            ++is;
            tmp = a[is];
        } else if (tmp < b[it]) {
            tmp += a[is+2];
            a[is+3] += a[is+1];
            is += 2;
            ++ans;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    debug(tmp, it, b[it]);
    if (it < b.size()) {
        if (b[it] != tmp) {
            cout << -1 << endl;
            return;
        }
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