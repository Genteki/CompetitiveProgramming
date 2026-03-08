// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
int dxs[4] = {0, 0, -1, 1}, dys[4] = {-1, 1, 0, 0};
void solve() {
    queue<pair<int, int>> q;
    int n, m, d;
    cin >> n >> m >> d;
    vector a(n, vector<char>(m));
    vector dst(n, vector<int>(m, 1e8));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'H') {
                q.emplace(i, j);
                dst[i][j] = 0;
            }
        }
    }
    int ans = q.size();
    while (!q.empty()) {
        auto [i, j] = q.front();
        int di = dst[i][j];
        q.pop();
        debug(i, j, di);
        if (di == d) continue;

        for (int p = 0; p < 4; ++p) {
            int nx = dxs[p] + i, ny = dys[p] + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny <= m) {
                if (a[nx][ny] == '.' && dst[nx][ny] > di + 1) {
                    debug(nx, ny, di + 1, ans);
                    dst[nx][ny] = di + 1;
                    q.emplace(nx, ny);
                    ++ans;
                }
            }
        }
    }
    cout << ans;
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