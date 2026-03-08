#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 x, y, a;
    cin >> x >> y >> a;
    i64 z = x + y;
    a %= z;
    if (a < x) cout << "NO\n";
    else cout << "YES\n";
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