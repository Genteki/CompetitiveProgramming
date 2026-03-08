// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

void solve() {
    i64 sx, sy, tx, ty;
    int n;
    cin >> n;
    cin >> sx >> sy >> tx >> ty;
    vector<i64> x(n), y(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    vector<vector<int>> adj(n+2);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j<n; ++j) {
            if (abs(x[i]-x[j]) > 2*(r[i]+r[j]) || abs(y[i]-y[j] > 2 * (r[i]+r[j]))) continue;
            ui64 d2 = (ui64)(x[i] - x[j]) * (ui64)(x[i] - x[j]) +
                      (ui64)(y[i] - y[j]) * (ui64)(y[i] - y[j]);
            ui64 r2 = (ui64)(r[i] + r[j]) * (ui64)(r[i] + r[j]);
            ui64 rd2 = (ui64)(r[i] - r[j]) * (ui64)(r[i] - r[j]);
            // cout << i << " " << j << " " << d2 << " " << r2 << " " << rd2 << endl;
            if (d2 <= r2 && d2 >= rd2) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        ui64 ds2 =
            (ui64)(x[i] - sx) * (x[i] - sx) + (ui64)(y[i] - sy) * (y[i] - sy);
        ui64 dt2 =
            (ui64)(x[i] - tx) * (x[i] - tx) + (ui64)(y[i] - ty) * (y[i] - ty);
        ui64 r2 = r[i] * r[i];
        if (ds2 == r2) {
            adj[n].push_back(i);
            adj[i].push_back(n);
        }
        if (dt2 == r2) {
            adj[n+1].push_back(i);
            adj[i].push_back(n+1);
        }
    }
    vector<bool> viewed(n+2, false);
    auto dfs = [&](auto&& self, int node, int target) -> bool {
        viewed[node] = true;
        for (int to : adj[node]) {
            // cout << to << " ";

            if (to == target) {
                return true;
            }
            if (!viewed[to]) {
                bool a = self(self, to, target);
                if (a) return true;
            }
        }
        return false;
    };
    bool ans = dfs(dfs, n, n+1);
    // for (auto adji : adj) {
    //     for (auto adjii : adji) 
    //         cout << adjii << " ";
    //     cout << endl;
    // }
        
    if (ans) cout << "Yes";
    else cout << "No";

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