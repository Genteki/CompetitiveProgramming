// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto& i : p) cin >> i, --i;
    for (auto& i : q) cin >> i, --i;

    vector<int> ordq(n);
    for (int i = 0; i < n; ++i) {
        ordq[q[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << q[p[ordq[i]]] + 1 << " ";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}