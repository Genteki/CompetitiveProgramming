// d.cpp

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    i64 n = s.size();
    int q;
    cin >> q;
    vector<i64> qs(q);
    input(qs);
    for (auto qi : qs) {
        i64 m = n;
        i64 k = 0;
        bool flip = false;
        while (m < qi) {
            m *= 2;
            k++;
        }
        while (m >= n) {
            if (qi > m) {
                qi -= m;
                flip = !flip;
            }
            m = m / 2;
        }
        char ans = s[qi-1];
        debug(qi, n);
        if (flip) {
            if (ans >= 'a' && ans <= 'z') {
                ans = ans - 'a' + 'A';
            } else {
                ans = ans - 'A' + 'a';
            }
        }
        cout << ans << " ";
    }
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