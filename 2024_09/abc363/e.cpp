// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m, y;
    cin >> n >> m >> y;
    vector h(n, vector<int>(m, 0));
    vector viewed(n, vector<bool>(m, false));
    for (auto & hi : h) 
        for(auto &hii : hi) 
            cin >> hii;

    map<int, vector<pair<int,int>>> mp;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        mp[h[i][0]].emplace_back(i, 0);
        if(m > 1) mp[h[i][m-1]].emplace_back(i, m-1);
        viewed[i][0] = true;
        viewed[i][m-1] = true;
    }
    for (int i = 1; i < m - 1; ++i) {
        mp[h[0][i]].emplace_back(0, i);
        if(n > 1) mp[h[n-1][i]].emplace_back(n-1, i);
        viewed[0][i] = true;
        viewed[n-1][i] = true;
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    auto dfs = [&](auto&& self, int ui, int uj, int l) -> void {
        for (int i = 0; i < 4; ++i) {
            int vi = ui + dx[i];
            int vj = uj + dy[i];
            if (vi >= 0 && vi < n && vj >= 0 && vj < m && !viewed[vi][vj]) {
                viewed[vi][vj] = true;
                if (h[vi][vj] > l) {
                    mp[h[vi][vj]].emplace_back(vi, vj);
                } else {
                    ans++;
                    self(self, vi, vj, l);
                }
            }
        }
    };

    for (int e = 1; e <= y; ++e) {
        if (mp.begin()->first == e) {
            auto tmp = mp.begin()->second;
            for (auto& [ui, uj] : tmp) {
                ++ans;
                dfs(dfs, ui, uj, e);
            }
            mp.erase(e);
        }
        cout << (m*n - ans) << endl;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}