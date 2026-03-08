#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void solve() {
    i64 p, q, n;
    cin >> p >> q >> n;
    vector g(n+1, vector<int>()), g_(n+1, vector<int>());
    for (int i = 0; i <= n-p; ++i) {
        g[i].push_back(i+p);
    }
    for (int i = 0; i <= n-q; ++i) {
        g[i+q].push_back(i);
    }
    // find cycle
    vector<int> viewed(n+1, 0);
    auto dfs = [&](this auto&& self, int u) -> bool {
        viewed[u] = 1;
        for (auto v : g[u]) {
            if (viewed[v] == 2) continue;
            if (viewed[v]==1) return false;
            if (!self(v)) return false;
        }
        viewed[u] = 2;
        return true;
    };
    for (int i = 0; i <= n; ++i) {
        if (!viewed[i]) {
            bool acyclic = dfs(i);
            if (!acyclic) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    vector<i64> ps(n + 1, 0);
    vector<int> ord;
    fill(viewed.begin(), viewed.end(), 0);
    auto dfs2 = [&](this auto && self, int u) -> void {
        viewed[u] = true;
        for (auto v : g[u]) {
            if (!viewed[v]) {
                self(v);
            }
        }
        ord.push_back(u);
    };
    for (int i = 0; i <= n; ++i) {
        if (!viewed[i]) {
            dfs2(i);
        }
    }
    reverse(ord.begin(), ord.end());
    for (int i = 0 ; i < n + 1; ++i) {
        ps[ord[i]] = i;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ps[i+1] - ps[i] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}