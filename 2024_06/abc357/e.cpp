#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f;  // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<int> g(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        g[i] = x;
    }

    int ai = 0;
    vector<bool> viewed(n, 0);
    vector<bool> checked(n, 0);
    vector<set<int>> tab(n);
    auto dfs = [&](auto&& self, int source, int node) -> void {
        viewed[node] = true;
        tab[source].insert(node);
        if (!viewed[g[node]]) {
            self(self, source, g[node]);
        }
    };
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        viewed = vector<bool>(n, 0);
        if (!checked[g[i]]) {
            dfs(dfs, i, i);
        } else {
            tab[i] = tab[g[i]];
            tab[i].insert(i);
        }
        checked[i] = true;
        ans += tab[i].size();
    }
    cout << ans << endl;
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