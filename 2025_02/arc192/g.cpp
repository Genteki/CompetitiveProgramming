// g.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 N = 2e5;
vector<i64> prime(N+1, 1), semi_prime(N+1, 0);

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n+1, 0);
    for (i64 i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        a[x]++;
    }
    i64 pn = 0;
    i64 ans = 0;
    for (i64 i = 2; i <= n; ++i) {
        if (a[i]) {
            if (prime[i]) {
                ans += (pn * a[i]);
                pn += a[i];
            } else if (semi_prime[i]) {
                debug(i,a[i]);
                ans += (a[i] * (a[i] - 1) / 2 + a[i]);

                ans += (a[i] * a[semi_prime[i]]);

                if((i / semi_prime[i]) != semi_prime[i]) ans += (a[i] * a[i/semi_prime[i]]);
                debug(i, semi_prime[i], ans);
            }
        }
    }
    debug(pn);
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (i64 i = 2; i <= N; ++i) {

        if (prime[i]) {
            for (i64 j = i; j * i <= N; ++j) {
                prime[i*j] = 0;
            }
        }
    }
    for (i64 i = 2; i <= N; ++i) {
        if (prime[i]) {
            for (i64 j = i; j * i <= N; ++j) {
                if (prime[j]) {
                    semi_prime[i*j] = i;
                }
            }
        }
    }

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}