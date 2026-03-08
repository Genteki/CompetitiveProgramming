#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    i64 ans = 0;
    ans += i64(floorl(sqrtl(n / 2)));
    ans += i64(floorl(sqrtl(n / 4)));
    cout << ans;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}