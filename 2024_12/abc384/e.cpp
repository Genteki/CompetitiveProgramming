// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
typedef __int128_t i128;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
i64 dx[4] = {1, -1, 0, 0};
i64 dy[4] = {0, 0, 1, -1};

struct point {
    i64 val, x, y;
    point(i64 pval, i64 px, i64 py) : val(pval), x(px), y(py) {}
    bool operator<(const point& other) const { return val > other.val; }
};

void solve() {
    i64 h, w, x;
    cin >> h >> w >> x;
    i64 p, q;

    vector a(h, vector<i64>(w));
    cin >> p >> q;

    for (auto & ai : a) for (auto && aii : ai) cin >> aii;
    --p; --q;
    i64 s = 0;
    priority_queue<point>  pq;
    vector viewed(h, vector<i64>(w, 0));
    pq.emplace(a[p][q], p, q);
    viewed[p][q] = true;

    debug(h, w, x, p , q);
    while(!pq.empty()) {
        auto up = pq.top();
        i64 u = up.val, ui = up.x, uj = up.y;
        debug(s, ui, uj, a[ui][uj]);
        pq.pop();
        if ( s == 0 || u < (s + x - 1) / x) {
            s += u;
        } else {
            break;
        }
        for (int i = 0; i < 4; ++i) {
            i64 vi = ui + dx[i];
            i64 vj = uj + dy[i];
            if (vi >= 0 && vj >=0 && vi < h && vj < w && !viewed[vi][vj]) {
                pq.emplace(a[vi][vj], vi, vj);
                viewed[vi][vj] = true;
            }
        }
    }
    cout << s;
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