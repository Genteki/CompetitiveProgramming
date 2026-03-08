// e.cpp
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

void solve(int test_cases) {
    int n, k;
    cin >> n >> k;
    vector<int> a1(n), a2(n);
    input(a1);
    int m1, m2;
    cin >> m1;
    vector<vector<int>> g1(n, vector<int>()), g2(n, vector<int>());
    vector<pair<int, int>> e1, e2; 
    for (int k = 0; k < m1; ++k) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        g1[v].push_back(u);
        e1.emplace_back(v, u);
    }
    input(a2);
    cin >> m2;
    for (int k = 0; k < m2; ++k) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g2[v].push_back(u);
        e2.emplace_back(v, u);
    }
    int o1 = accumulate(all(a1), 0);
    int o2 = accumulate(all(a2), 0);
    if (o1 + o2 != n) {
        cout << "NO" << endl;
        return;
    }
    vector<int> pos1(n, -1), pos2(n, -1), v1(n, false), v2(n, false);
    pos1[0] = 0; pos2[0] = 0;
    auto dfs = [&](auto&& self, vector<vector<int>> &g, int v, vector<int> &pos) -> void {
        int p = (pos[v] + 1) % k;
        for (auto u : g[v]) {
            if (pos[u] == -1) {
                pos[u] = p;
                self(self, g, u, pos);
            }
        }
    };
    dfs(dfs, g1, 0, pos1);
    dfs(dfs, g2, 0, pos2);
    if (o2 == 0 || o1 == 0) {
        cout << "YES" << endl;
        return;
    }
    debug(test_cases);
    debug(pos1);
    debug(pos2);

    vector<i64> cnta(k, 0), cntb(k, 0), s;
    for (int i = 0; i < n; ++i) {
        if (a1[i] == 0) {
            pos1[i] = (pos1[i] - 1 + k) % k;
            cnta[pos1[i]]++;
        } else {
            pos1[i] = (pos1[i] + 1 + k) % k;
            cnta[pos1[i]] += n;
        }
        if (a2[i] == 0) {
            cntb[pos2[i]]+=n;
        } else {
            cntb[pos2[i]]++;
        }
    }

    s.insert(s.end(), all(cnta));
    s.push_back(-1);
    s.insert(s.end(), all(cntb));
    s.insert(s.end(), all(cntb));
    int p = s.size();
    debug(cnta);
    debug(cntb);
    vector<int> pi(p, 0);
    for (int i = 1; i < p; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
        if (j == k) {
            cout << "YES" << endl;
            return;
        }
    }
    debug(pi);
    cout << "NO" << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(test_cases);
    }
}