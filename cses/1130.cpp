#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < n -1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    vector<bool> viewed(n, 0);

    auto dfs = [&](auto && self , int node ) -> void {
        viewed[node] = true;
        if (g[node].size() == 1) {
            g[g[node][0]].clear();
            g[node].clear();
            ++ ans;
        } else {
            for(int ni : g[node]) {
                if (!viewed[ni]) {
                    self(self, ni);
                }
            }
            if (!g[node].empty()) {
                ans++;
                for 
                g[node].clear();
            }
        }
    };
    
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
