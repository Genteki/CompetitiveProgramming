#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    auto dfs = [&](auto&&self, int x) -> void {
        self(self, x);
    };
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