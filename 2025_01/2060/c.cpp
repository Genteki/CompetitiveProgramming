// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    vector<int> b(n+1, 0);
    for (auto ai : a) b[ai]++;
    int ans = 0;
    for (int i = 1; i <= min(n, k); ++i) {
        if (i == (k/2) and k % 2 == 0) {
            ans += (2 * (b[i]/2));
        } else if (k-i > 0 and k-i <= n) {
            ans += min(b[i], b[k-i]);
        }
    }
    cout << (ans/2) << endl;
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