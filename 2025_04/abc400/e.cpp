#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 N = 1e6+5;
vector<i64> prime(N, 1);
vector<i64> good(N, 0);
vector<i64> ngood(N, 0);
vector<pair<i64,i64>> r;
vector<i64> l;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n;
    cin >> n;
    i64 low = 0, high = l.size();
    while(high - low > 1) {
        i64 mid = (low + high) / 2;
        i64 x = l[mid] * l[mid];
        if (x>n) high =mid;
        else low = mid;
    }
    cout << l[low]*l[low] << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (i64 i = 2; i*i < N; ++i) {
        if (prime[i]) {
            for (i64 j = i*i; j < N; j += i) {
                prime[j] = 0;
            } 
        }
    }

    for (i64 i = 2; i < N; ++i) {
        if (prime[i]) {
            for (i64 j = i ; j < N; j *= i) {
                good[j] = i;
            }
        }
    }

    for (i64 i = 2; i < N; ++i) {
        if (good[i]) {
            r.emplace_back(i, good[i]);
        }
    }

    for (auto [i,xi] : r) {
        for (auto [j, xj] : r) {
            if (j >= i or i * j >= N) break;
            if (xi == xj) continue;
            ngood[i*j] = 1;
        }
    }
    for (i64 i = 2; i < N; ++i) {
        if (ngood[i]) {
            l.push_back(i);
        }
    }

    debug(l.size());

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}