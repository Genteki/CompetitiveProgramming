#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = (s[i] == '1') ? 1 : -1;
    }

    vector<i64> ss(n+1, 0);
    for (int i = n - 1; i >= 0; --i) {
        ss[i] = a[i] + ss[i + 1];
    }
    ss[0] = 0;
    sort(all(ss));
    reverse(all(ss));
    debug(ss);
    i64 x = 0;
    for (int i = 0; i < ss.size(); ++i) {
        x += ss[i];
        if (x >= k) {
            cout << (i + 2) << endl;
            return;
        }
    }
    cout << -1 << endl;

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