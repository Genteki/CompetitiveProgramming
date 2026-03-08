// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    sort(a.begin(), a.end());
    vector<i64> b;
    for (int i = 1; i < n; ++i) {
        if (a[i] % a[0] == 0) {
            b.push_back(a[i]/a[0]);
        }
    }
    if (b.empty()) {
        cout << "No" << endl;
        return;
    }
    i64 g = b[0];
    for (auto bi : b) {
        g = __gcd(g, bi);
    }
    if (g == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No\n";
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