#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    vector<i64> a(5,0);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    i64 x = 0;
    i64 ans  =0;
    a[2] = a[0] + a[1];
    if (a[1] + a[2] == a[3]) ++ans;
    if (a[2] + a[3] == a[4]) ++ans;
    if (a[0] + a[1] == a[2]) ++ans;
    x = max(x, ans);
        ans = 0;
        a[2] = a[3] - a[1];
        if (a[1] + a[2] == a[3]) ++ans;
        if (a[2] + a[3] == a[4]) ++ans;
        if (a[0] + a[1] == a[2]) ++ans;
        x = max(x, ans);
        ans = 0;
        a[2] = a[4] - a[3];
        if (a[1] + a[2] == a[3]) ++ans;
        if (a[2] + a[3] == a[4]) ++ans;
        if (a[0] + a[1] == a[2]) ++ans;
        x = max(x, ans);
    cout << x<< endl;
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