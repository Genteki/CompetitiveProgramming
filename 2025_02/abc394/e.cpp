// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;
const int inf = 1e9;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<int>> d(n, vector<int>(n, inf));

    for (auto & gi : g) for (char & gii : gi) cin >> gii;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        // if (g[i][i] != '-') {
            // debug(i);
            d[i][i] = 0;
            q.emplace(i, i);
        // }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i!= j and g[i][j] != '-') {
                    d[i][j] = 1;
                    q.emplace(i, j);
            }
        }
    }
    vector gc(26, vector(n, vector<int>()));
    vector gcr(26, vector(n, vector<int>()));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != '-') {
                gc[g[i][j] - 'a'][i].push_back(j);
                gcr[g[i][j] - 'a'][j].push_back(i);
            }
        }
    }
    debug(d);
    while(!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        int d0 = d[u][v];
        for (int i = 0; i < 26; ++i) {

            for (auto ui : gcr[i][u]) {
                for (auto vi : gc[i][v]) {
                    if (chmin(d[ui][vi], d0+2)) {
                        q.emplace(ui, vi);
                    }
                }
            }
        }
    }
    for (auto & di : d) {
        for (auto & dii : di) {
            if (dii == inf) cout << -1 << " ";
            else cout << dii << " ";
        }cout << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}