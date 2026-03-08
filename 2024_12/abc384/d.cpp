// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, t;
    cin >> n >> t;
    vector<i64> a(n);
    input(a);
    i64 s = accumulate(a.begin(), a.end(), 0LL);
    t %= s;
    vector<i64> ps(2 * n + 1, 0);
    for (int i = 0; i < n * 2; ++i) {
        ps[i + 1] = ps[i] + a[i % n];
    }
    cerr << t << endl;
    for (int i = 0; i < n; ++i) {
        i64 r = t + ps[i];
        cerr << r << endl;
        auto it = lower_bound(ps.begin(), ps.end(), r);
        if (*it == r) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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