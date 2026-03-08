#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;

    // Input the 2D array
    vector<vector<i64>> a(n, vector<i64>());
    for (i64 i = 0; i < n; ++i) {
        i64 l;
        cin >> l;
        a[i].resize(l);
        input(a[i]);
    }

    // Vector to store the MEX and second MEX
    vector<pair<i64, i64>> b(n);

    // Compute the MEX and second MEX for each array `a[i]`
    for (i64 i = 0; i < n; ++i) {
        sort(all(a[i]));  // Sort each subarray
        i64 l = a[i].size();

        vector<bool> present(l + 2,
                             false);  // Track the presence of numbers in `a[i]`
        for (i64 num : a[i]) {
            if (num < l + 2) present[num] = true;
        }

        i64 mex1 = 0, mex2 = 0;
        while (present[mex1]) ++mex1;  // First missing number (MEX)
        mex2 = mex1 + 1;
        while (present[mex2]) ++mex2;  // Second missing number
        b[i] = {mex1, mex2};
    }

    // Set to store unique MEX values and second MEX values
    set<i64> s;
    vector<i64> pts;

    for (auto& [u, v] : b) {
        s.insert(u);  // Add unique MEX and second MEX values to the set
        s.insert(v);
    }

    for (auto si : s) {
        pts.push_back(si);  // Store all unique points in `pts`
    }

    // Create a graph based on the values of `b`
    vector<vector<i64>> g(pts.back() + 1);
    for (auto& [u, v] : b) {
        g[v].push_back(u);
    }
    debug(g);

    // Initialize mx array to track maximum reachable values
    vector<i64> mx(pts.back() + 1, -1);

    // DFS function to update mx values
    auto dfs = [&](auto&& self, i64 node, i64 value) -> void {
        mx[node] = max(mx[node], value);
        for (auto v : g[node]) {
            if (mx[v] != -1) continue;
            self(self, v, value);
        }
    };

    // Run DFS from each point in reverse order
    for (i64 i = pts.back(); i >= 0; --i) {
        if (mx[i] != -1) continue;
        mx[i] = i;
        dfs(dfs, i, i);
    }

    i64 ans = 0;
    if (m <= pts.back()) {
        ans = pts.back() * (m + 1LL);
    } else {
        i64 r = pts.back();

        ans = ans + (i64)m * (m + 1) / 2LL;
        ans = ans + (i64)r * (r + 1) / 2LL;
    }
    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}