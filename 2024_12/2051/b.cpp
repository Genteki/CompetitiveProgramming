// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int s = a + b + c;
    int ans = n / s * 3;
    n -= (ans /3 * s);
    if (n == 0) {
    } else if (n <= a) {
        ans++;
    } else if (n <= (a + b)) {
        ans += 2;
    } else {
        ans += 3;
    }
    cout << ans << endl;
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