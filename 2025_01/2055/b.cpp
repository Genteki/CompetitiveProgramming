// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n ;
    vector<i64> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int cnt = 0;
    i64 delta = 0;
    i64 x = 1e10;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cnt++;
            delta = b[i] - a[i];
        } else {
            x = min(x, a[i] - b[i]);
        }
    }
    if (cnt > 1) {
        cout << "NO" << endl;
    } else if (cnt == 0) {
        cout << "YES" << endl;
    } else {
        if (delta <= x) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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