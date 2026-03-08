#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) cin >> a[i];

//     int high = n / 2 + 1, low = 0;
//     while (high - low > 1) {
//         int mid = (high + low) / 2;
//         debug(high, low, mid);

//         bool flag = true;
//         for (int i = 0; i < mid; ++i) {
//             if (a[i] > (a[n - mid + i] / 2)) {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag) {
//             low = mid;
//         } else {
//             high = mid;
//         }
//     }
//     cout << low;
//     return;
// }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) b[i] = distance(a.begin(), 
        upper_bound(a.begin(), a.end(), a[i]/2)) - i;
    int bg = n - n / 2;

    int l = n / 2;
    auto it = min_element(b.end()-l, b.end());
    int x = *it;
    cout << min(n/2, x+n-1);

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