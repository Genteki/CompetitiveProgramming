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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    input(a);
    sort(all(a));
    bool flag = true;
    map<int, int> mp;
    int i = 0, h = 0;
    a.push_back(INT_MAX);
    while(flag == true && i <= n) {
        debug(i, a[i], h, mp[h%x]);
        if (a[i] == h) {
            debug(1);
            ++h;
            ++i;
        } else if (a[i] < h) {
            debug(2);
            mp[a[i] % x]++;
            ++i;
        } else {
            if (mp[h%x] > 0) {
                debug(3);
                mp[h % x]--;
                if (mp[h % x] == 0) mp.erase(h%x);
                ++h;
            } else {
                debug(4);
                // cout << h << endl;
                flag = false;
            }
        }
    }
    cout << h << endl;
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