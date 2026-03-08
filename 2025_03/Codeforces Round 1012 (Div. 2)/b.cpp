// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, m;
    cin >> n >> m;
    debug(n,m);
    vector<vector<int>> g(n, vector<int>(m)), viewed(n,vector<int>(m,0));
    for (auto&gi:g) for (auto&gii:gi) {
        char c;
        cin >> c;
        gii = c - '0';}
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                viewed[i][j] = 1;
            } else break;
    }
    }
    for (int j = 0;j  < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (g[i][j] == 1) {
                viewed[i][j] = 1;
            } else break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] and !viewed[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    debug(viewed);
    cout << "YES\n";
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