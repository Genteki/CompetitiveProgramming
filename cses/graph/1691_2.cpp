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
    vector<unordered_set<int>> g(n);
    // cout << n << " " << m << endl;
    vector<int> deg(n,0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].insert(y); g[y].insert(x);;
        deg[x]++; deg[y]++;
    }
    int odd_deg_ct = 0;
    for (int degi : deg) {
        if (degi % 2) {
            odd_deg_ct++;
        }
    }
    if (odd_deg_ct) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<pair<int, int>> ans;
    auto dfs = [&](auto &&self, int s) -> void {
        while (!g[s].empty()) {
            int i = *g[s].begin();
            g[s].erase(i); g[i].erase(s);
            self(self, i);
            ans.push_back({s,i});
        }
    };
    dfs(dfs, 0);
    if (ans.size() != (m)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << (1+it->first) << " ";
    }
    cout << 1 << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}