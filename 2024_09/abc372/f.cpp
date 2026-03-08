// f.cpp

#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int MOD = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n, 1), q(n, 1);
    vector<pair<int, int>> edges;
    for (;m--;) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        edges.emplace_back(x, y);
    }
    for (int i = 0; i < k; ++i) {
        for (auto [u,v] : edges) {
            u = ((u - i) % n + n) % n;
            v = ((v - i) % n + n) % n;
            p[u] = (p[u] + p[v]) % MOD;
        }
    }
    debug(p);

    cout << p[(k - 1 + n) % n] << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}