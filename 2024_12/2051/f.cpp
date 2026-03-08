// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    i64 ans = 1;
    bool disable = false; int vac = 0;
    --m;
    int l1 = 0, r1 = -1, l2 = m, r2 = m, l3 = n, r3 = n - 1;
    map<int, int> v;
    while(q--) {
        int x;
        cin >> x;
        --x;
        if (r1 != -1) {
            if(x > r1) {
                r1++;
                r1 = min(n-1, r1);
            } else {
                r1 = max(r1, 0);
                l3 = min(l3, n - 1);
            }
        }
        if (l3 != n) {
            if(x < l3) {
                l3--;
                l3 = max(0, l3);
            } else {
                r1 = max(r1, 0);
                l3 = min(l3, n - 1);
            }
        }
        if (!disable) {
            if (x > r2) {
                r2++;
                r2 = min(n - 1, r2);
            } else if (x < l2) {
                l2--;
                l2 = max(0, l2);
            } else {
                r1 = max(r1, 0);
                l3 = min(l3, n - 1);
                // if (r2 == x)
                //     --r2;
                // else if (l2 == x)
                //     ++l2;
                // else if (vac == x) vac = 0;
                // else vac = x;
                // if (l2 > r2) disable = true;
                if (l2 == x && r2 == x) {
                    disable = true;
                }
            }
        }

        debug(l1, r1, l2, r2, l3, r3);
        if(!disable) ans = (min(l2-1, r1) - l1 + 1) + (r2-l2+1) + (r3 - max(r2+1, l3) + 1) - bool(vac);
        else ans = min(r1-l1+1 + r3-l3+1, n);
        cout << ans << " ";
    }
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