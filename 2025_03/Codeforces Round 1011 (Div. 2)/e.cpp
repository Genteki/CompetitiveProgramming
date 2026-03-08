// e.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int M = 1000000000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    i64 sa = 0, sb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sb += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mb = b[n-1];
    int ma = a[n-1];

    i64 delta = sa - sb;
    if (delta < 0) {
        cout << -1 << "\n";
        return;
    }
    if (delta == 0) {
        if (a == b) {
            cout << (ma+1) << "\n";
        } else {
            cout << -1 << "\n";
        }
        return;
    }

    vector<i64> mods;
    for (i64 i = 1; i * i <= delta; i++) {
        if (delta % i == 0) {
            mods.push_back(i);
            if (i * i != delta) mods.push_back(delta / i);
        }
    }
    sort(mods.begin(), mods.end());
    int ans = -1;
    for (auto k : mods) {
        if (k <= mb or k > ma or k > M) continue; 
        vector<int> r;
        for (int i = 0; i < n; i++) {
            r.push_back(a[i] % k);
        }
        sort(r.begin(), r.end());
        if (r == b) {
            ans = k;
            break;
        }
    }
    cout << ans << "\n";
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