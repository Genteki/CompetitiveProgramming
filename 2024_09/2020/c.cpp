// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 b, c, d, a = 0;
    cin >> b >> c >> d;
    vector<int> btb(62), btc(62), btd(62), bta(62, -1);
    for (int i = 0; i < 62; ++i) {
        btb[i] = bool(b & (1LL << i));
        btc[i] = bool(c & (1LL << i));
        btd[i] = bool(d & (1LL << i));
    }
    debug(b);
    for (int i = 0; i < 62; ++i) {
        if (btd[i] == 1) {
            if (btb[i] == 0 && btc[i] == 0) bta[i] = 1;
            else if (btb[i] == 1 && btc[i] == 0) bta[i] = 1;
            else if (btb[i] == 1 && btc[i] == 1) bta[i] = 0;
            else {
                cout << -1 << endl;
                return;
            }
        } else {
            if (btb[i] == 0 && btc[i] == 0) bta[i] = 0;
            else if (btb[i] == 0 && btc[i] == 1) bta[i] = 1;
            else if (btb[i] == 1 && btc[i] == 1) bta[i] = 1;
            else {
                cout << -1 << endl;
                return;
            }
        }
    }
    debug(bta);
    for (int i = 0; i < 62; ++i) {
        if (bta[i]) {
            a |= i64(1LL << i);
        }
    }
    cout << a << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}