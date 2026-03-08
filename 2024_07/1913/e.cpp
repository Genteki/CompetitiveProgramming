#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
constexpr int inf = 0x3f3f3f3f;
typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto& ai : g) input(ai);
    vector<int> a(n), b(m);
    input(a); 
    input(b);
    
    int sa = accumulate(all(a), 0);
    int sb = accumulate(all(b), 0);
    if (sa != sb) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    
    int N = n + m + 2;
    int i_row = 0, i_col = n, i_source = N-2, i_sink = N-1;
    vector<vector<int>> adj(N);
    vector<vector<int>> capacity(N, vector<int>(N, 0));
    int all1 = 0;
    for (int i = 0; i < n; ++i) {
        adj[i_source].push_back(i_row + i);
        adj[i_row + i].push_back(i_source);
        int si = accumulate(all(g[i]), 0); all1 += si;
        if (a[i] > si) capacity[i_source][i_row + i] = a[i] - si;
        else capacity[i_row + i][i_source] = si - a[i];
    }
    for (int i = 0; i < m; ++i) {
        adj[i_sink].push_back(i_col+i);
        adj[i_col+i].push_back(i_sink);
        int si = 0;
        for (int j = 0; j < n; ++j) si += g[j][i];
        if (b[i] > si) capacity[i_col + i][i_sink] = b[i] - si;
        else capacity[i_sink][i_col+i] = si - b[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            adj[i * m + j].push_back(i_col + j);
            adj[i * m + j].push_back(i_row + i);
            adj[i_col + j].push_back(i * m + j);
            adj[i_row + i].push_back(i * m + j);
            if (g[i][j] == 1) {
                capacity[i * m + j][i_row + i] = 1;
                capacity[i_col + j][i * m + j] = 1;
            } else {
                capacity[i_row + i][i * m + j] = 1;
                capacity[i * m + j][i_col + j] = 1;
            }
        }
    }

    // we should use bfs for max flow, but the row is quite fixed so we could chosse 
    vector<int> parent(N);
    vector<bool> viewed(N, false);
    int flow = 0, curr_flow = inf;
    auto bfs = [&] (int s, int t) -> int {
        fill(all(parent), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.emplace(s, 1);
        while(!q.empty()) {
            auto [node, cur_flow] = q.front();
            q.pop();
            for (int & to : adj[node]) {
                if (parent[to] == -1 && capacity[node][to]) {
                    q.emplace(to, 1);
                    parent[to] = node;
                    if (to == t) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    };

    if (sa < all1) swap(i_sink, i_source);
    while(bfs(i_source, i_sink)) {
        flow++;
        int cur = i_sink;
        while(cur != i_source) {
            int prev = parent[cur];
            capacity[prev][cur] --;
            capacity[cur][prev]++;
            cur = prev;
        }
    }
    cout << all1 << " " << sa << endl;
    bool flag = true;
    // for (int to : adj[i_source]) {
    //     if (capacity[i_source][to] || capacity[to][i_source]) flag = false;
    // }
    // for (int to : adj[i_sink]) {
    //     if (capacity[i_sink][to] || capacity[to][i_sink]) flag = false;
    // }

    if (flow == abs(all1-sa)) {
        cout << flow << endl;
    } else {
        cout << -1 << endl;
    }

    
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}