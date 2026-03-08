// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)


#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    const i64 inf = 1e10;
    i64 n, q;
    cin >> n >> q;
    vector<i64> a(n);
    input(a);
    sort(all(a));
    debug(a);
    for (; q--;) {
        i64 b, k;
        cin >> b >> k;
        i64 low = -1, high = 1e9;
        while(high - low > 1) {
            i64 mid = (high + low) / 2;
            auto left = lower_bound(all(a), b - mid);
            auto right = upper_bound(all(a), b + mid);
            int d = right - left;
            debug(d);
            if (d >= k) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        cout << high << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}