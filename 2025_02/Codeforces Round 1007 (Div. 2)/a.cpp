#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int x;
    cin >> x;
    if (x%3==1) cout << "YES\n";
    else cout << "NO\n";
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