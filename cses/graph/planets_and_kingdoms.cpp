// planets_and_kingdoms.cpp
// strongly connected components

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
    vector<vector<int>> g(n), g_(n);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g_[y].push_back(x);
    }

    vector<vector<int>> components;
    vector<bool> viewed(n, false);
    vector<int> component;
    stack<int> s;

    auto dfs1 = [&] (auto && self, int node) -> void {
        viewed[node] = true;
        for (int & subi : g[node]) {
            if (!viewed[subi]) {
                self(self, subi);
            }
        }
        s.push(node);
    };

    auto dfs2 = [&] (auto && self, int node) -> void {
        viewed[node] = true;
        component.push_back(node);
        for (int & subi : g_[node]) {
            if (!viewed[subi]) {
                self(self, subi);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!viewed[i]) {
            cerr << i << endl;
            dfs1(dfs1, i);
        }
    }

    fill(all(viewed), false);

    while(!s.empty()) {
        int t = s.top();
        s.pop();
        if (!viewed[t]) {
            // cout << t << endl;
            cerr << t << endl;
            component.clear();
            dfs2(dfs2, t);
            components.push_back(component);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i  < components.size(); ++i) {
        for (int & ci : components[i]) {
            ans[ci] = i;
        }
    }
    cout << components.size() << endl;
    for (auto ansi : ans) cout << (ansi+1) << " ";
    cout << endl;

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