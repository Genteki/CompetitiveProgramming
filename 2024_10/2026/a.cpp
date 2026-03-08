#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    vector<pair<int,int>> pts(4);
    pts[0] = {0, 0};
    bool s = false;
    if (x > y) {swap(x, y); s = true;}
    pts[2] = {x, 0};
    if (k <= x) {
       pts[1] = {x, 0};
       pts[3] = {x, y};
    } else {
        pts[1] = {x, ceil(sqrt(double(k * k - x * x)))};
        pts[3] = {x - pts[1].second, x};
    }
    // assert((pts[0].first - pts[1].first) * (pts[2].second - pts[3].second) ==
    //        (pts[0].second - pts[1].second) *
    //            (pts[2].first - pts[3].first));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (!s) {
                cout << pts[i * 2 + j].first << " " << pts[i*2+j].second << " ";
            } else {
                cout << pts[i * 2 + j].second << " " << pts[i * 2 + j].first
                     << " ";
            }
        }cout << endl;
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