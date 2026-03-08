#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> l(n, vector<char>(m));
    for (auto & li : l) {
        for (auto & lii : li) {
            cin >> lii;
        } 
    }
    debug(l.size());
    queue<pair<int, int>> q1, q2;
    vector d_monster(n, vector<int>(m, INT_MAX)), d_a(n, vector<int>(m, INT_MAX));
    int start_i, start_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0;j < m; ++j) {
            if (l[i][j] == 'A'){ 
                q2.emplace(i, j); 
                d_a[i][j] = 0;
                start_i = i; start_j = j;
            }
            if (l[i][j] == 'M') {q1.emplace(i, j); d_monster[i][j] = 0;}
        }
    }
    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    string s("RLDU");
    while(!q1.empty()) {
        auto &[i, j] = q1.front();
        q1.pop();
        int d = d_monster[i][j];
        for (auto [di, dj] : dir) {
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                if (d_monster[ni][nj] > d + 1 && l[ni][nj] != '#') {
                    d_monster[ni][nj] = d + 1;
                    q1.emplace(ni , nj);
                }
            }
        }
    }
    while (!q2.empty()) {
        auto &[i, j] = q2.front();
        q2.pop();
        int d = d_a[i][j];
        for (auto [di, dj] : dir) {
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                if (d_a[ni][nj] > d + 1 && l[ni][nj] == '.') {
                    d_a[ni][nj] = d + 1;
                    q2.emplace(ni, nj);
                }
            }
        }
    }
    debug(d_a);
    debug(d_monster);
    vector<char> path;
    vector viewed(n, vector<int>(m, 0));
    auto dfs = [&](auto && self, int ui, int uj) -> bool {
        viewed[ui][uj] = true;
        if (ui == 0 || ui == n-1 || uj == 0 || uj == m - 1){return true;}
        for (int i = 0; i < 4; ++i) {
            auto [di, dj] = dir[i];
            int ni = ui + di;
            int nj = uj + dj;
            if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                if (!viewed[ni][nj] && d_a[ni][nj] == (d_a[ui][uj] + 1) && d_monster[ni][nj] > d_a[ni][nj] && l[ni][nj] == '.') {
                    if (self(self, ni, nj)) {
                        path.push_back(s[i]);
                        return true;
                    }
                }
            }
        }
        return false;
    };
    if (dfs(dfs, start_i, start_j)== 0) {
        cout << "NO" << endl;
    } else {
        reverse(all(path));
        cout << "YES" << endl;
        cout << path.size() << endl;
        for (auto pi : path) cout << pi; 
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