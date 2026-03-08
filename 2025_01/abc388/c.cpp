// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&ai : a) cin >> ai;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = 2 * a[i];
        auto it = lower_bound(a.begin(), a.end(), x);
        ans += distance(it, a.end());
    }
    cout << ans ;
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