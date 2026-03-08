#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    int px = 0, py= 0, lastx = -1, lasty = -1;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        px += xi;
        py += yi;
        if (px >= lastx) {
            sx+=m;
        } else {
            sx += (m-(lastx - px));
        }
        if (py >= lasty) {
            sy += m;
        } else {
            sy += (m - (lasty - py));
        }
        lastx = px+m;
        lasty = py+m;
    }
    cout << (2 * (sx + sy)) << endl;
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