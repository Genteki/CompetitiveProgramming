#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int a[15] {0};
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i < 15; ++i) a[i] = 3;
    int x;
    cin >> x;
    int y;
    y = x / 15 * 3;
    x %= 15;
    y += a[x];
    cout << y << endl;
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