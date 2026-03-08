// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, x, k;
    cin >> n >> x >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c =='L') a[i] = -1;
        else a[i] = 1;
    }

    int timer = 0;
    int ans = 0;
    while(timer < min(n,k) and x != 0) {
        x += a[timer];
        ++timer;
    }
    if (x != 0) {
        cout << 0 << endl;
        return;
    }
    int y = 0, cy = -1;
    for (int i = 0; i < n; ++i) {
        y += a[i];
        if (y == 0) {
            cy = i + 1;
            break;
        }
    }
    if (cy == -1) {
        cout << 1 << endl;
        return;
    } else {
        cout << (1 + (k - timer) / cy) << endl;
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