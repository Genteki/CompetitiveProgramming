// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector g(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            if (c == '1') {
                g[i][j] = 1;
            } else {
                g[i][j] = 0;
            }
        }
    }
    vector<int> p(n, -1);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = i+1; j < n; ++j) {
            x += g[i][j];
        }
        x = n - 1 - i - x;
        int v = 0;
        while (x > 0) {
            if (p[v] == -1) {
                x--;
            } 
            ++v;
            // else {
            //     if (g[p[v]][i] == )
            // }
        }
        while(p[v] != -1) ++v;
        p[v] = i;
        debug(p);
    }
    for (auto pi : p) cout << (pi + 1) << " ";
    cout << endl;
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