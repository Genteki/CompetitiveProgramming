// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, s;
    cin >> n >> s;
    vector<i64> a(n);
    for (i64 &ai : a) cin >> ai;
    sort(a.begin(), a.end());
    i64 miss = 0;
    i64 last = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] - last > 1) {
            miss = miss + (last + 1 + a[i] - 1) * (a[i] - last - 1) / 2;
        }
        last = a[i];
    }
    if (miss > s) {
        cout << "NO\n";
        return;
    }
    s -= miss;
    while(s > 0) {
        s -= (++a.back());
    }
    if (s== 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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