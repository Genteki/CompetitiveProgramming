#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<char> c(n);
    input(c);

    vector<int> leaves;
    stack<int> stk;
    stk.push(0);
    auto dfs = [&] (auto &&self, int v, int parent=-1) -> void {
        if (g[v].size() == 1 && g[v][0] == parent) {
            leaves.push_back(v);
        } else {
            for (auto to : g[v]) {
                if (to != parent) self(self, to, v);
            }
        }
    };
    
    dfs(dfs, 0);
    int others = 0;
    for (int i = 1; i < n; ++i) {
        if (c[i] == '?') others++;
    }
    char c0 = c[0];
    int z = 0, o = 0, q = 0;
    
    for (int li = 0; li < leaves.size(); ++li) {
        int i = leaves[li];
        if (c[i] == '0') {
            z++;
        } else if (c[i] == '1') {
            o++;
        } else {
            q++;
        }
    }
    others -= q;
    debug(leaves);
    if (c0 == '?') {
        if (z == o && q % 2 && others % 2) {
            cout << (z + (q + 1) / 2) << endl;
            return;
        }
        if (z < o) {
            swap(z, o);
        }
        debug(z, o, q);
        cout << (z + (q / 2)) << endl;
    } else {
        if (c0 == '1') {
            swap(z, o);
        }
        cout << (o + (q+1) / 2) << endl;
    }

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}