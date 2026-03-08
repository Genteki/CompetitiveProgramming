#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 inf = __LONG_LONG_MAX__;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<i64>> cap(n, vector<i64>(n, 0));
    while(m--) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        cap[x][y] = 1;
        cap[y][x] = 1;
    }
    vector<int> parent(n, -1);
    auto bfs = [&](int s, int t) -> i64 {
        fill(all(parent), -1);
        parent[s] = -2;
        i64 new_flow = inf;
        queue<pair<int, i64>> q;
        q.emplace(s, new_flow);
        while(!q.empty()) {
            auto [cur, f] = q.front();
            q.pop();
            for (auto to : g[cur]) {
                if (parent[to] == -1 && cap[cur][to]) {
                    parent[to] = cur;

                    new_flow = min(f, cap[cur][to]);
                    if (to == t) {
                        return new_flow;
                    }
                    q.emplace(to, new_flow);
                }
            }
        }
        return 0;
    };  

    i64 flow = 0;
    int s = 0, t = n-1;
    i64 new_flow;
    // flow = bfs(s,t);
    while(new_flow = bfs(s,t)) {
        // cout << new_flow<< endl;
        flow += new_flow;
        int cur = t;
        while(cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
        // break;
    }
    cout << flow << endl;
    
    vector<bool> viewed(n, false);
    auto dfs = [&] (auto&& self, int node) ->void {
        viewed[node] = true;
        for (int to : g[node]) {
            if (!viewed[to] && cap[node][to]) {
                self(self, to);
            }
        }
    };
    // for (auto ci : cap) {
    //     for (auto cii : ci) {
    //         cout << cii << " ";
    //     } cout << endl;
    // }
    dfs(dfs, 0);
    vector<pair<int,int>> min_cut;
    for (int i = 0; i < n; ++i) {
        if (viewed[i]) {
            for (auto j : g[i]) {
                if (!viewed[j]) {
                    min_cut.push_back({i,j});
                }
            }
        }
    }

    for (auto [i, j] : min_cut) {
        cout << (i+1) << " " << (j+1) << endl;
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