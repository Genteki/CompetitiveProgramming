#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n,  ans = 1;
    cin >> n;
    while(n > 3) {
        n/=4;
        ans *=2;
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