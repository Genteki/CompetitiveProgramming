// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, p;
    cin >> n >> p;
    vector<i64> a(n);
    for (i64 & ai : a) cin >> ai;
    auto c = a;
    sort(a.begin(), a.end());
    auto b = a;
    b.erase(unique(b.begin(), b.end()), b.end());

    if (b.size() == p) {
        cout << 0 << endl;
        return;
    }
    i64 m1 = p-1;
    for (int i = b.size()-1; i>=0; --i) {
        if (b[i] != m1) {
            break;
        } else {
            m1--;
        }
    }
    i64 m2 = c.back()-1;
    while(m2 >= 0 and *lower_bound(b.begin(), b.end(), m2) == m2) {
        --m2;
    }
    debug(b);
    debug(m2);
    if (m2 ==-1) {
        cout << (m1-c.back()) << endl;
        return;
    }
    i64 ans = p - c.back();
    i64 x = 1, idx = n-2;
    while (idx>=0 and c[idx] == p-1) {
        --idx;
    }
    if(idx >=0 ) x = c[idx] + 1;
    if ( *lower_bound(b.begin(), b.end(), x) != x) {
        b.push_back(x);
        sort(b.begin(), b.end());
    }
    while (m2 >= 0 and *lower_bound(b.begin(), b.end(), m2) == m2) {
        --m2;
    }
    if (m2 ==-1) {
        cout << ans << endl;
    } else {
        cout << (ans + m2) << endl;
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