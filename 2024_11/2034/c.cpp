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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (auto & gi : g) {
        for (auto & gii : gi) {
            cin >> gii;
        }
    }
    vector<vector<int>> good(n, vector<int>(m, 0));
    vector<vector<int>> viewed(good);
    queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        if (g[i][0] == 'L') {
            good[i][0] = 1;
            q.emplace(i, 0);
        }
        if (g[i][m-1] == 'R') {
            good[i][m-1] = 1;
            q.emplace(i, m-1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (g[0][i] == 'U') {
            good[0][i] = 1;
            q.emplace(0, i);
        }
        if (g[n-1][i] == 'D') {
            good[n-1][i] = 1;
            q.emplace(n-1, i);
        }
    }
    debug(good);
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        viewed[i][j] = true;
        if (i + 1 < n && g[i+1][j] == 'U') {
            good[i + 1][j] = 1;
            if (!viewed[i + 1][j]) q.emplace(i + 1, j);
            viewed[i + 1][j] = 1;
        }
        if (i - 1 >= 0 && g[i - 1][j] == 'D') {
            good[i - 1][j] = 1;
            if (!viewed[i - 1][j]) q.emplace(i - 1, j);
            viewed[i - 1][j] = 1;
        }
        if (j + 1 < m && g[i][j + 1] == 'L') {
            good[i][j + 1] = 1;
            if (!viewed[i][j+1]) q.emplace(i, j + 1);
            viewed[i][j + 1] = 1;
        }
        if (j - 1 >= 0 && g[i][j - 1] == 'R') {
            good[i][j-1] = 1;
            if (!viewed[i][j-1]) q.emplace(i, j-1);
            viewed[i][j-1] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '?') {
                bool flag = true;
                if (i + 1 < n && good[i+1][j] == 0) {
                    flag = false;
                }
                if (i - 1 >= 0 && good[i-1][j] == 0) {
                    flag = false;
                }
                if (j + 1 < m && good[i][j + 1] == 0) {
                    flag = false;
                }
                if (j - 1 >= 0 && good[i][j - 1] == 0) {
                    flag = false;
                }
                good[i][j] = flag;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!good[i][j]) ++cnt;
        }
    }
    cout << cnt << endl;
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