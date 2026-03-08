// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
    using namespace std;

typedef long long i64;
int N = 1501;
struct s {
    vector<int> v;
    s() { v = vector<int>(N, -1); }
};
void setmax(int& a, int b) { a = max(a, b); }
void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<i64> a(l);
    input(a);
    vector b(n, vector<i64>(m));
    for (auto& bi : b) {
        input(bi);
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp.find(b[i][j]) == mp.end()) {
                mp[b[i][j]] = vector<int>(N, -1);
            }
            setmax(mp[b[i][j]][i], j);
        }
    }
    auto dfs = [&](auto&& self, int round, int row, int col, bool T) -> bool {
        if (round >= l) return false;
        bool result = false;
        int ai = a[round];
        if (mp.find(ai) == mp.end()) return false;
        int x = 0;
        int cur = -1;
        for (int r = n-1; r >= row; --r) {
            debug(r);
            int c = mp[ai][r];
            if (c >= col) {
                debug(c, cur);
                if (cur >= c) continue;
                ++x;
                result = result || (!self(self, round + 1, r + 1, c + 1, !T));
                cur = c;
            }
        }
        return result;
    };
    bool ans = dfs(dfs, 0, 0, 0, true);
    debug(ans);
    if (ans)
        cout << "T" << endl;
    else
        cout << "N" << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}