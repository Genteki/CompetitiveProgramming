// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;
    string r;
    cin >> r;
    vector a(n, vector<i64>(m));
    for (auto & ai : a) for (auto &aii : ai) cin >> aii;
    vector<i64> sr(n, 0), sc(m, 0);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sr[i] += a[i][j];
            sc[j] += a[i][j];
            s += a[i][j];
        }
    }
    i64 avg = 0;
    int x = 0, y = 0;
    for (auto c : r) {
        if (c == 'D') {
            a[x][y] = avg - sr[x];
        } else {
            a[x][y] = avg - sc[y];
        }
        sr[x] += a[x][y];
        sc[y] += a[x][y];
        if (c == 'D') {
            x++;
        } else {
            y++;
        }
    }
    a[n-1][m-1] = avg - sr[n-1];
    for (auto & ai : a) {
        for (auto &aii : ai) {
            cout << aii << " ";
        }
        cout << endl;
    }
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