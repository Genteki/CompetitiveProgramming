// d.cpp
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<int> row(w), col(h);
    for (int i = 0; auto& ri : row) ri = (i++);
    for (int i = 0; auto& ri : col) ri = (i++);
    vector<set<int>> rows(h, set<int>(all(row))), cols(w, set<int>(all(col)));
    for (; q--;) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        if (rows[r].find(c) != rows[r].end()) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            if (!cols[c].empty()) {
                auto it = cols[c].lower_bound(r);
                int dr1=-1, dr2=-1;
                if (it != cols[c].begin()) {
                    dr1 = *prev(it);
                }
                if (it != cols[c].end()) {
                    dr2 = *it;
                }
                if (dr1 != -1) {
                    rows[dr1].erase(c);
                    cols[c].erase(dr1);
                }
                if (dr2 != -1) {
                    rows[dr2].erase(c);
                    cols[c].erase(dr2);
                }
            } 
            if (!rows[r].empty()) {
                auto it = rows[r].lower_bound(c);
                int dc1=-1, dc2=-1;
                if (it != rows[r].begin()) {
                    dc1 = *prev(it);
                }
                if (it != rows[r].end()) {
                    dc2 = *it;
                }
                if (dc1 != -1) {
                    rows[r].erase(dc1);
                    cols[dc1].erase(r);
                }
                if (dc2 != -1) {
                    rows[r].erase(dc2);
                    cols[dc2].erase(r);
                }
            }
        }
        debug(rows);
    }
    i64 ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}