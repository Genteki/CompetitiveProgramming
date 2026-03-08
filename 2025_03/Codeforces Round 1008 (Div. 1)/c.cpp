#include <bits/stdc++.h>

#include "algorithm/comb.h"
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
using namespace std;
template<class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) { 
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i] = int(s[i] == '1') * 2 - 1 ;
    }
    vector<int> ps(n+1, 0);
    while(q--) {
        int x;
        cin >> x;
        --x;
        a[x] = - a[x];
        mint ans = 0;

        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + a[i];
        }
        debug(a);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                i64 s = abs(ps[j]-ps[i]);
                i64 t = s / 2;
                i64 v = (s + 1) / 2;
                ans += (t * v);
                debug(i, j, ans.val());
            }
        }
        cout << ans << endl;
    }

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