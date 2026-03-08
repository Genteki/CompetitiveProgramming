// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<int> p(n, -1);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int j;
        cin >> j; --j;
        p[i] = j;
        g[i].push_back(j);
        g[j].push_back(i);
    }


    auto dfs = [&](auto&&self, int node) -> i64 {
        if (g[node].size() == 1 && g[node][0] == p[node]) return a[node];
        i64 m = INT_MAX;
        for (int u : g[node]) {
            if (u == p[node]) continue;
            i64 thism = self(self, u);
            m = min(thism, m);
        }
        if (a[node] >= m) return m;
        else return ((a[node] + m) / 2); 
    };

    i64 ans = INT_MAX;

    for (auto v : g[0]) {
        ans = min(ans, dfs(dfs, v));
        // cout << dfs(dfs, v) << " ";
    }
    ans += a[0];
    cout << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
