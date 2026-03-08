// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (auto & ai : a) for (auto & aii : ai) cin >> aii;
    int min_x = 1e9, min_y = 1e9, max_x = -1, max_y = -1;
    for (int i = 0 ; i < h; ++i) {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == '#') {
                min_x = min(min_x, i);
                max_x = max(max_x, i);
                min_y = min(min_y, j);
                max_y = max(max_y, j);
            }
        }
    }
    for (int i = min_x; i <= max_x; ++i) {
        for (int j = min_y; j <= max_y; ++j) {
            if (a[i][j] == '.') {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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
