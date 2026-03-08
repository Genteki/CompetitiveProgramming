#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<vector<int>> g(n);

    // Read the tree edges
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<i64>> dp(n, vector<i64>(26, 0));
    auto f = [&](auto&& self, int node, int parent = -1) -> void {
        i64 s1 = a[node], s2 = a[node] * 2;
        for(int i = 0; i < 26; ++i) {
            dp[node][i] = a[node] * (i + 1);
        }
        for (int to : g[node]) {
            if (to == parent) continue;
            self(self, to, node);
        }
        for (int i = 0; i < 26; ++i) {
            for (int to : g[node]) {
                if (to == parent) continue;
                i64 tmp = __LONG_LONG_MAX__;
                for (int j = 0; j < 26; ++j) {
                    if(j != i) tmp = min(dp[to][j], tmp);
                }
                dp[node][i] += tmp;
            }
        }
    };

    f(f, 0);

    cout << (*min_element(all(dp[0]))) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
    return 0;
}