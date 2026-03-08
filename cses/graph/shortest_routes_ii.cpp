// floyd-warshell algorithm

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
const long long inf = LONG_MAX;
typedef long long i64;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, i64>>> g(n);
    vector<vector<i64>> d(n, vector<i64>(n, inf));

    for (;m--;) {
        int x, y; long long l;
        cin >> x >> y >> l;
        --x; --y;
        g[x].emplace_back(y, l);
        g[y].emplace_back(x, l);
        d[x][y] = min(d[x][y], l);
        d[y][x] = min(d[x][y], l);
    }
    for (int k = 0; k < n; ++k) {
        d[k][k] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] != inf && d[k][j] != inf) {
                    d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
                }
            }
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout <<( d[x][y]==inf ? -1 : d[x][y]) << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}