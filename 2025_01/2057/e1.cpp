#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const i64 inf = 1e18;
struct Edge {
    i64 u, v, w;
    Edge(i64 pu, i64 pv, i64 pw) : u(pu), v(pv), w(pw) {}
    friend bool operator < (const Edge& lhs, const Edge & rhs) {return lhs.w < rhs.w;}
};
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    vector dist(n, vector<i64>(n, inf));
    vector dp(m+1, vector(n, vector<i64>(n, inf)));
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        i64 u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.emplace_back(u, v, w);
        dist[u][v] = dist[v][u] = 1;
    }
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n;++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < inf and dist[j][k] < inf)
                chmin(dist[i][j], dist[i][k] + dist[j][k]);
            }
        }
    }
    dp[0] = dist;
    sort(edges.begin(), edges.end());
    for (int k = 0; k < m; ++k) {
        dp[k+1] = dp[k];
        auto [u, v, w] = edges[k];
        dp[k+1][u][v] = 0;
        dp[k+1][v][u] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chmin(dp[k + 1][i][j], dp[k][i][u] + dp[k][v][j]);
                chmin(dp[k + 1][i][j], dp[k][i][v] + dp[k][u][j]);
                dp[k+1][j][i] = dp[k+1][i][j];
            }
        }
    }
    debug(dp[m]);
    auto check = [&]() -> void {
        i64 a, b, k;
        cin >> a >> b >> k;
        --a;
        --b;
        for (int i = 0; i < m; ++i) {

            if (dp[i+1][a][b] < k) {
                cout << edges[i].w << " ";
                return;
            }
        }
        debug(a, b, k, dp[m][a][b]);

        cout << edges[0].w << " ";
    };

    while(q--) {
        check();
    }
    cout << endl;

    return;
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