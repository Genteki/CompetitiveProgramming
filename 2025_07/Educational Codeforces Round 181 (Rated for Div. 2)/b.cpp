// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 a,b,k;
    cin >> a >> b >> k;
    if (a > b) swap(a, b);
    i64 c = __gcd(a, b);

    if ( (b/c) <= k) cout << 1 << "\n";
    else cout << "2\n";
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