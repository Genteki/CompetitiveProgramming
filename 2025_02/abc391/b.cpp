// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n, 0)), b(m, vector<char>(m, 0));
    
    for (auto & ai : a) for (auto & aii : ai) cin >> aii;
    for (auto & ai : b) for (auto & aii : ai) cin >> aii;
    
    for (int x = 0; x <= n-m; ++x) {
        for (int y = 0; y <= n-m; ++y) {
            bool flag = true;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[x+i][y+j] != b[i][j]) flag= false;
                }
            }
            if (flag) {
                ++x; ++y;
                cout << x << " " << y;
                return;
            }
        }
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
