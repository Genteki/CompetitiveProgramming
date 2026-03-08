// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const i64 N = 2e6 + 5;
void solve() {
    i64 n;
    cin >> n;
    i64 sqn = sqrt(double(n));
    vector<bool> prime(N + 1, true);
    vector<i64> ps;
    for (int i = 2; i * i <= N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) ps.push_back(i);
    }
    i64 ans = 0;
    for (i64 i = 0; i < ps.size(); ++i) {
        i64 p = ps[i];

        if (p * p < n) {
            i64 q = n / (p * p);
            q = sqrt(double(q));
            i64 j = upper_bound(ps.begin(), ps.end(), q) - ps.begin();
            // debug(p, q, i, j);
            if (j >= i + 1) {
                ans += (j - i - 1);
            } else {
                break;
            }
        } else {
            break;
        }
    }

    for (i64 i = 2; i < 200; ++i) {
        debug(pow(i, 8LL));

        if (prime[i] && pow(i, 8) <= n) {
            ++ans;
        } else if (pow(i, 8) > n) {
            break;
        }
    }
    cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}