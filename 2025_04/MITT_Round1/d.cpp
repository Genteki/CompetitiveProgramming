// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const int inf = 1e9;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k);
    for (auto & xi : x) {cin >> xi, --xi;}
    vector g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vector<int> d(n, inf);
    vector<pair<int,int>> ans;
    d[0] = 0;
    q.push(0);
    int p = 0;
    if(x[0]==0) p = 0;
    else p = 1;
    set<int> s;
    for (auto xi:x) s.insert(xi);
    int last = 0;
    for (int i = 0; i < k; ++i) {
        d[x[i]] = p;
        if (x[i] != last) ans.emplace_back(last,x[i]);
        ++p;
        s.erase(x[i]);
        q.push(x[i]);

        while(!q.empty()) {
            auto u = q.front();
            if (d[u] >= p) break;
            q.pop();
            if (s.contains(u)) {
                cout << -1 << endl;
                return;
            }
            for (auto v : g[u]) {
                if (chmin(d[v], d[u]+1)) q.push(v);
            }
        }
        last = x[i];
    }
    cout << ans.size() << endl;
    for (auto [x,y]:ans) cout << (x+1) << " " << (y+1) << "\n";
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