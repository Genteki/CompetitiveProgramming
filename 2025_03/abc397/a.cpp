#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    double x;
    cin >> x;
    if (x >= 38.0) {
        cout << 1;
    } else if (x >= 37.5) cout << 2;
    else cout << 3;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}