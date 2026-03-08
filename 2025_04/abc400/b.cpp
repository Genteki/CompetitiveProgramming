// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;
    i64 ans = 0, x = 1;
    i64 inf = 1e9;
    for (int i = 0; i <= m; ++i) {
        ans += x;
        if (ans > inf) {
            cout << "inf";
            return;
        }
        x *= n;
    }   
    cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

        solve();
}