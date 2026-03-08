// https://atcoder.jp/contests/dp/tasks/dp_g
// dp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int x ,y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
    }
    vector<bool> used(n, false);
    vector<int> length(n, 0);

    auto dfs = [&](auto &&self, int node) -> void {
        used[node] = true;
        if (g[node].empty()) {
            length[node] = 0;
        } else {
            for (int subi : g[node]) {
                if (!used[subi]) self(self, subi);
                length[node] = max(length[node], 1 + length[subi]);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(dfs, i);
    }
    cout << *(max_element(all(length))) << endl;
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