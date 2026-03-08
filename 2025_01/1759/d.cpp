// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n,m;
    cin >> n >> m;
    i64 x = 1;

    while(n % 10 == 0) {
        n /= 10;
        x *= 10;
    }
    while(n % 5 == 0 and m >= 2) {
        n /= 5;
        m /= 2;
        x *= 10;
    }
    while (n % 2 == 0 and m >= 5) {
        n /= 2;
        m /= 5;
        x *= 10;
    }
    while (m >= 10) {
        m /= 10;
        x *= 10;
    }
    i64 ans = n * m;
    while(m) {
        if (m * n % 10 == 0) {
            ans = m * n * x;
            cout << ans << endl;
            return;
        }
        m--;
    }
    cout << (ans * x) << endl;
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
