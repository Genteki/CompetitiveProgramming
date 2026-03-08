#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, s, k;
    cin >> n >> s >> k;
    i64 p = 0;
    for (;n--;) {
        i64 x, y;
        cin >> x>> y;
        p += x*y;
    }
    if (p < s) p += k;
    cout << p;

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