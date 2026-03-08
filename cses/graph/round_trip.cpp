#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cycle_start, cycle_end;
    vector<int> cycle, p(n, -1);
    auto dfs = [&](auto&&self, int v, int parent=-1) -> bool {
        visited[v] = true;
        for (auto & to : g[v]) {
            if (to == parent) continue;
            if (visited[to]) {
                cycle_start = to;
                cycle_end = v;
                return true;
            }
            p[to] = v;
            if (self(self, to, p[to])) {
                return true;
            }
        } 
        return false;
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(dfs, i)) {
                cycle.push_back(cycle_end);
                while(p[cycle.back()] != cycle_start) {
                    cycle.push_back(p[cycle.back()]);
                }
                cout << (cycle.size() + 2) << endl;
                for (int ci : cycle) cout << (ci+1) << " ";
                cout << (cycle_start+1) << " " << (cycle_end+1) << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;


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