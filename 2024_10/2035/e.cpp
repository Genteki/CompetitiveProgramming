// e.cpp

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

template<typename T>
T ceil(T a, T b) {
    if (b == 0) return 1e18;
    return (a + b - 1) / b;
}

void solve() {
    i64 x, y, z, k;
    cin >> x >> y >> z >> k;
    i64 atk = 0;
    i64 base_cost = 0;
    i64 cost = 1e18;
    
    while (z > 0) {
        for (i64 natk = max(1LL, atk); natk < atk + k; natk = ceil(z, ceil(z, natk)-1))  {
            if (natk <= atk + k) {
                i64 new_cost = base_cost + (natk - atk) * x + ceil(z, natk) * y;
                cost = min(new_cost, cost);
                debug(natk, atk, z, cost);
            }
        }
        atk += k;
        base_cost += (k * x + y);
        z -= atk;
    }
    cost = min(base_cost, cost);
    cout << cost << endl;
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