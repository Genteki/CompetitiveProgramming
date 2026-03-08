#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int x = 0, y = 0;
    int i = 0;
    debug(s, n);

    for (int i = 0; i < n-2; ++i) {
        if (s[i]=='1' and s[i+2] == '1') s[i+1] = '1';
    }
    for (int i = 0; i < n; ++i) y += (s[i] == '1');
    for (int i = 0 ; i < n -2 ; ++i) {
        if (s[i] == '1' and s[i+2] == '1') s[i+1] = '0';
    }
    for (int i = 0; i < n; ++i) x += (s[i] == '1');
    
    cout << x << " " << y << endl;
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