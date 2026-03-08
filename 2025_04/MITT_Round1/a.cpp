#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 2025;
        for (int i = 4; i < n; ++i) cout << 0;
        cout << endl;
    }  else {
        cout << 42025;
        for (int i = 5; i < n; ++i) cout << 0;
        cout << endl;
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