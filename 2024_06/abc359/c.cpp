// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 sx, sy, tx, ty;

    cin >> sx >> sy >> tx >> ty;
    i64 dy = abs(ty-sy);
    i64 s_right_ext;
    if ((sx + sy) % 2 == 0) {
        s_right_ext = 1;
    } else {
        s_right_ext = 0;
    }
    if (s_right_ext && tx > sx) sx++;
    else if (!s_right_ext && tx < sx) sx--;
    i64 dx = abs(sx - tx);
    i64 rm = (sx + s_right_ext + dy);
    i64 lm = (sx - (1LL - s_right_ext) - dy);
    // if (rm >= ty && ty >= lm) {
    //     // cout << "1: ";
    //     cout << dy << endl;
    // } else {
    //     i64 dx = min(abs(rm - tx), abs(lm - tx));
    //     cout << ( dx / 2 + dy) << endl;
    // }
    if (dx <= dy) cout << dy << endl;
    else {
        // cout << dx << " ";
        i64 ans = ((dx - dy + 1) / 2 + dy);
        cout << ans << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}