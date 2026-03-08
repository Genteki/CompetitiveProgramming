// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));
    for (auto &ai : a) for (auto&aii : ai) cin >> aii;
    for (auto &ai : b) for (auto&aii : ai) cin >> aii;

    vector<int> per_row(h), per_col(w);
    iota(per_row.begin(), per_row.end(), 0);
    iota(per_col.begin(), per_col.end(), 0);
    int ans = 1e9;
    int opi = 0;
    do {
        do {
            bool good = true;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (a[per_row[i]][per_col[j]] != b[i][j]) {
                        good = false;
                    }
                }
            }
            if (good) {
                int cur_ans = 0;
                for (int i = 0; i < h; ++i) {
                    for (int j = i + 1; j < h; ++j) {
                        if (per_row[i] > per_row[j]) ++cur_ans;
                    }
                }
                for (int i = 0; i < w; ++i) {
                    for (int j = i + 1; j < w; ++j) {
                        if (per_col[i] > per_col[j]) ++cur_ans;
                    }
                }
                ans = min(ans, cur_ans);
            }
        } while(next_permutation(per_col.begin(), per_col.end()));
    } while(next_permutation(per_row.begin(), per_row.end()));
    if (ans >= 1e9) cout << -1;
    else cout << ans;
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