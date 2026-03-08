// flood fill

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    vector<bool> viewed(n*m, false);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    auto dfs = [&](auto&&self, int x, int y) -> void {
        viewed[x*m+y] = true;
        for (int k = 0; k < 4; ++k) {
            if (x+dx[k]>=0 && x+dx[k]<n && y+dy[k]>=0 && y+dy[k]<m) {
                if(!viewed[(x+dx[k])*m + y+dy[k]] && a[x+dx[k]][y+dy[k]]=='.') {
                    self(self, x+dx[k], y+dy[k]);
                }
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' && !viewed[i * m + j]) {
                // cout << i << j << " ";

                dfs(dfs, i, j);
                ++ans;
            }
        }
    }
    cout << ans;
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