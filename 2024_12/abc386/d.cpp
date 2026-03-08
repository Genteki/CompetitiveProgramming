// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
bool chmax(i64& a, i64 b){ return b > a ? a = b, true : false; }
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }

void solve() {
    i64 n, m;
    cin >> n >> m;
    map<i64, i64> black_max, white_min;
    white_min[0] = n+1;
    for (int i = 0; i < m; ++i) {
        int r, c;
        char color;
        cin >> r >> c >> color;
        if (color == 'B') {
            chmax(black_max[r], c);
        } else {
            if (white_min.find(r) == white_min.end()) white_min[r] = c;
            else chmin(white_min[r], c);
        }
    }
    for (auto it = white_min.begin(); it != prev(white_min.end()); ++it) {
        chmin(next(it)->second, it->second);
    }
    for (auto it = white_min.rbegin(); it != prev(white_min.rend()); ++it) {
        chmax(next(it)->second, it->second);
    }
    if (!white_min.empty()) {
        for (auto& [r, c] : black_max) {
            auto it = white_min.upper_bound(r);
            i64 wc = prev(it)->second;
            if (wc <= c) {
                cout <<"No";
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