#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 p,q,x,y;
    cin >> p >> q >> x >> y;
    if (p <=x and (p+100)>x and q <=y and (q+100) > y) cout << "Yes";
    else cout << "No";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}