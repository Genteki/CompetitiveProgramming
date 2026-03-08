// c.cpp
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
    string s;
    cin >> s;
    string maxt = s;
    int maxl=0, maxr=0;

    int n = s.size();
    for (int r = n-1; r >= 0; --r) {
        int cur_max = r;
        string t = s;
        int l = r;
        for (; l >= 0; --l) {
            int pos = n - 1 - r + l;
            if (s[pos] == '0') {
                if (s[l] == '1') {
                    t[pos] = '1';
                    cur_max = l;
                }
            } else {
                if (s[l] == '1') {
                    t[pos] = '0';
                }
            }
        }
        string x = s;
        for (int i = 0; i < r-cur_max+1; ++i) {
            x[n-1-i] = t[n-1-i];
        }
        debug(cur_max, r, t, maxt);
        if (x >= maxt) {
            maxl = cur_max;
            maxr = r;
            maxt = x;
        }
    }
    cout << 1 << " " << n << " " << (maxl+1) << " " << (maxr+1) << endl;
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