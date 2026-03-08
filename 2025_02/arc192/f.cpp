// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> viewed(n, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        map<int,int> cnt;
        cnt[a[i]]++;
        for (auto v : g[i]) {
            cnt[a[v]]++;
        }
        for (auto&[x, y] : cnt) {
            if (y >= 2) {
                ans[x]=1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i];
    cout << endl;
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