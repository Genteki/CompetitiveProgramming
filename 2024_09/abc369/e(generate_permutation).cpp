// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<tuple<i64, i64, i64>> bridge(m);
    for (auto & bi : bridge) {
        i64 u, v, d;
        cin >> u >> v >> d;
        --u; --v;
        bi = {u, v, d};
    }
    vector<vector<i64>> distance(n, vector<i64>(n, INT64_MAX));
    for (i64 i = 0; i < n; ++i) distance[i][i] = 0;
    for (auto &[u, v, d] : bridge) {
        distance[u][v] = min(distance[u][v], d);
        distance[v][u] = min(distance[v][u], d);
    }
    for (i64 k = 0; k < n; ++k) {
        for (i64 j = 0; j < n; ++j) {
            for (i64 i = 0; i < n; ++i) {
                if (distance[i][k] < INT64_MAX && distance[j][k] < INT64_MAX) {
                    distance[i][j] = min(distance[i][k] + distance[j][k], distance[i][j]);
                    distance[j][i] = distance[i][j];
                }
            }
        }
    }

    debug(distance);

    i64 q;
    cin >> q;
    for (; q--;) {
        i64 ans = INT64_MAX;
        i64 k;
        cin >> k;
        vector<i64> b(k);
        for (auto & bi : b) {
            cin >> bi;
            --bi;
        }
        vector<i64> combination(k);
        vector<i64> used(k, false);
        for (i64 i = 0; auto &ci : combination) {
            ci = i;
            ++i;
        }
        auto gen_combination = [&](auto && self, vector<i64>& cur) -> void {
            if (cur.size() == k) {
                vector<i64> x(1<<k);
                for (i64 i = 0; auto &xi : x) {
                    xi = i; ++i;
                }
                for (auto &xi : x) {
                    i64 from = 0;
                    i64 d = 0;
                    for (i64 i = 0; auto &curi : cur) {
                        auto [u, v, l] = bridge[curi];
                        if (xi & (1 << i)) {
                            swap(u, v);
                        }
                        d = d + distance[from][u] + l;
                        from = v;
                        ++i;
                    }
                    d += distance[from][n - 1];
                    ans = min(d, ans);
                }
                debug(cur);
                return;
            }
            for (i64 i = 0; i < b.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    cur.push_back(b[i]);
                    self(self, cur);
                    cur.pop_back();
                    used[i] = false;
                }
            }
        };

        vector<i64> c;
        gen_combination(gen_combination, c);
        cout << ans << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}