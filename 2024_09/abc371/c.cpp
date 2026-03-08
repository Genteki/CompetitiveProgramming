// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    int mg, mh;
    cin >> mg;
    vector g(n, vector<bool>(n, false)), h(n, vector<bool>(n, false));
    for (;mg--;) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u][v] = !g[u][v];
    }
    cin >> mh;
    for (;mh--;) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        h[u][v] = !h[u][v];
    }
    vector a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = INT_MAX;

    vector<bool> used(n, false);
    vector<int> vertices(n, 0);
    for (int i = 0; i < n; ++i) vertices[i] = i;
    // auto gen_permuation = [&](auto &&self, vector<int> &cur, int l, int r) -> void {
    //     if (l != r) {
    //         for (int i = l; i <= r; ++i) {
    //             swap(cur[l], cur[i]);
    //             self(self, cur, i+1, r);
    //             swap(cur[l], cur[i]);
    //         }
    //     } else {
    //         int new_ans = 0;
    //         for (int i = 0; i < n; ++i) {
    //             for (int j = i; j < n; ++j) {
    //                 int ii = cur[i], jj = cur[j];
    //                 if (ii > jj) swap(ii, jj);
    //                 if (g[i][j] != h[ii][jj]) {
    //                     new_ans += a[ii][jj];
    //                     // new_ans += min(a[i][j], a[ii][jj]);
    //                 }
    //             }
    //         }
    //         debug(cur);
    //         ans = min(ans, new_ans);
    //     }
    // };
    // gen_permuation(gen_permuation, vertices, 0, n-1);

    do {
        int new_ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int ii = vertices[i], jj = vertices[j];
                if (ii > jj) swap(ii, jj);
                if (g[i][j] != h[ii][jj]) {
                    new_ans += a[ii][jj];
                }
            }
        }
        debug(vertices);
        ans = min(ans, new_ans);
    } while (next_permutation(all(vertices)));

    std::cout << ans;
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