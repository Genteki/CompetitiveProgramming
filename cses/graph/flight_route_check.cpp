// flight_route_check.cpp
// https://cses.fi/problemset/task/1682
// Strongly Connected Component

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
    vector<vector<int>> adj(n), adj_(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;--y;
        adj[x].push_back(y);
        adj_[y].push_back(x);
    }

    vector<int> scc;
    stack<int> s;
    vector<bool> viewed(n, false);

    auto dfs1 = [&](auto&& self, int node) -> void {
        viewed[node] = true;
        for (int subi : adj[node]) {
            if (!viewed[subi]) {
                self(self, subi);
            }
        }
        s.push(node);
    };

    auto dfs2 = [&](auto&& self, int node) -> void {
        viewed[node] = true;
        for (int subi : adj_[node]) {
            if (!viewed[subi]) {
                self(self, subi);
            }
        }
        scc.push_back(node);
    };

    for (int i = 0; i < n; ++i) {
        if (!viewed[i]) {
            dfs1(dfs1, i);
        }
    }
    vector<int> ans;
    fill(all(viewed), false);
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        if (!viewed[t]) {
            // cout << t << endl;

            ans.push_back(t);
            dfs2(dfs2, t);
        }
    }
    
    if (ans.size()==1) {
        cout <<"YES" << endl;
    } else {
        cout << "NO" << endl;
        // int a = ans[0], b = ans[1];
        cout << (ans[1]+1) << " " << (ans[0]+1) << endl;
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