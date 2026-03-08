// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    sort(all(a));
    int ans = INT_MAX;
    for (int i = 0; i < n -1; ++i) {
        i64 s = a[i] + a[i + 1];
        auto it = lower_bound(all(a), s);
        ans = min(ans, (i + (int)distance(it, a.end()) ) );
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