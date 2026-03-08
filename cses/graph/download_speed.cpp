#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
const long long inf = LONG_MAX;
using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<i64>> cap(n, vector<i64>(n, 0));
    while(m--) {
        int x, y; i64 f;
        cin >> x >> y >> f;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        cap[x][y] += f;
        // cap[y][x] = 0;
    }
    vector<int> parent(n);
    
    auto bfs = [&] (int s, int t) -> i64 {
        fill(all(parent), -1);
        parent[s] = -2;
        queue<pair<int, i64>> q;
        q.emplace(s, inf);

        while(!q.empty()) {
            auto [cur, flow] = q.front();
            q.pop();
            for (auto nxt : g[cur]) {
                i64 capi = cap[cur][nxt];
                if (parent[nxt] == -1 && capi) {
                    parent[nxt] = cur;
                    i64 new_flow = min(flow, capi);
                    if (nxt == t) return new_flow;
                    q.emplace(nxt, new_flow);
                }
            }
        }
        return 0;
    };

    i64 flow = 0;
    i64 new_flow = 0;
    int s = 0, t = n - 1;
    while (new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;
        while(cur != s) {
            cap[cur][parent[cur]] += new_flow;
            cap[parent[cur]][cur] -= new_flow;
            cur = parent[cur];
        }
    }

    cout << flow << endl;
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