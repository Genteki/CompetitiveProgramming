// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
void solve() {
    int n, m;
    cin >> n >> m;
    bool ans = true;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (auto& ai : a) for (auto&& aii : ai) cin >> aii;
    for (auto& bi : b) for (auto&& bii : bi) cin >> bii;
    vector<vector<int>> x(n, vector<int>(m)), y(n, vector<int>(m));
    for (int k = 0; k < 31; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                x[i][j] = a[i][j] >> k & 1;
                y[i][j] = b[i][j] >> k & 1;
            }
        }
        vector<vector<int>> g(n + m), g_(n+m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(y[i][j] == 1) {
                    g_[j+n].push_back(i);   
                    g[i].emplace_back(j + n);
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (y[i][j] == 0) {
                    g[j + n].push_back(i);
                    g_[i].push_back(j + n);
                }
            }
        }

        vector<int> viewed(n+m,0), ord;
        auto dfs1 = [&](auto&&self, int u) ->void{
            viewed[u] = true;
            for (auto v : g[u]) {
                if (!viewed[v]) {
                    self(self, v);
                }
            }
            ord.push_back(u);
        };
        for (int u = 0; u < n+m; ++u) if(!viewed[u]) dfs1(dfs1, u);
        reverse(ord.begin(), ord.end());
        fill(viewed.begin(), viewed.end(), 0);
        vector<vector<int>> ccs(n);
        vector<int> cc;
        auto dfs2 = [&](auto&&self, int u) -> void {
            viewed[u] = true;
            cc.push_back(u);
            for (auto v : g_[u]) {
                if (!viewed[v]) {
                    self(self, v);
                }
            }
        };
        for (int i : ord) {
            if (!viewed[i]) {
                cc.clear();
                dfs2(dfs2, i);
                ccs.push_back(cc);
            }
        }

        vector<int> gr(n+m, -1);
        for (int i = 0; auto &cci : ccs) {
            for (auto u : cci) {
                gr[u] = i;
            }
            ++i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (x[i][j] == 1 && y[i][j] == 0) {
                    if (ccs[gr[i]].size() > 1) {
                        cout << "NO" << endl;
                        return;
                    }
                } else if (x[i][j] == 0 && y[i][j] == 1) {
                    if (ccs[gr[j + n]].size() > 1) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "YES" << endl;
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