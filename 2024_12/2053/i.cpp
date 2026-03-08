#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    long long S = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
    }
    // We'll assume S >= 0 (given max|a_i| <= S).

    long long p = 0, minp = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        p += a[i];
        // While p-minp > S, fix it:
        while (p - minp > S) {
            count++;
            // conceptually we "insert a negative chunk and a positive chunk"
            // but in editorial code, we just do:
            minp = p - S;
        }
        // always keep track of the minimum prefix sum
        if (p < minp) {
            minp = p;
        }
    }

    long long m = n + count;
    cout << m << "\n";
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