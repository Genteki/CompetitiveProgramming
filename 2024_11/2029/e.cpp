// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;
const int N = 4e5 + 5;
typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve(vector<int>& m) {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int x = -1, y = 1e7;
    for (auto& ai : a) {
        if (m[ai] == -1) {
            if (x == -1) {
                x = ai;
            } else {
                cout << -1 << endl;
                return;
            }
        } else {
            y = min(y, m[ai]);
        }
    }
    debug(x);
    if (x == -1) {
        cout << 2 << endl;
    } else {
        for (auto& ai : a) {
            if (ai % x == 0) {
                continue;
            } else if (ai / m[ai] >= x) {
                continue;
            } else if (ai - m[ai] >= x * 2) {
                continue;
            } else {
                cout << -1 << endl;
                return;
            }
        }
        cout << x << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> m(N, -1);
    for (int i = 2; i < N; ++i) {
        if (m[i] == -1) {
            for (int j = 2; j <= N / i; ++j) {
                if (m[j * i] == -1) m[j * i] = i;
            }
        }
    }
    // debug(m);
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(m);
    }
}