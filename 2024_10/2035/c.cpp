// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> per(n, -1);
    int x = 1;
    while (n >= x * 2) {
        x *= 2;
    }
    if (n == 4) {
        per = {1, 2, 3, 4};
    }
    else if (n % 2 == 0) {
        if (x == n) {
            for (int i = 0; i < n; ++i) {
                per[i] = i + 1;
            }
            swap(per[0], per[n - 5]);
            
        } else {
            per[n-1] = x - 1;
            per[n-2] = x;
            int j = 0;
            for (int i = 1; i <= n; ++i) {
                if (i == x || i == x-1) continue;
                per[j] = i;
                j++;
            }
        }
    } else {
        per[n-1] = n;
        per[n-2] = n - 1;
        per[n-3] = 3;
        per[n-4] = 1;
        int j = 0;
        for (int i  = 1; i < n; ++i) {
            if (i == per[n-1] || i == per[n-2] || i == per[n-3] || i == per[n-4]) continue;
            per[j++] = i;
        }
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            k = (k & (per[i]));
        } else {
            k = (k | (per[i]));
        }
        // debug((0 | 5));
    }
    cout << k << endl;
    for (auto pi : per) cout << pi << " ";
    cout << endl;
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