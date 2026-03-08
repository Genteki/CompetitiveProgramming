#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    a[0] = 1;
    for (int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + 10;
    }
    vector<vector<int>> ans;
    auto next_per = [&](auto&& self, vector<int> &ar, int pos) -> void {
        if (n == pos) {
            ans.push_back(a);
            return;
        }
        if (pos != 0) ar[pos] = ar[pos - 1] + 10;
        while (ar[pos] <= (m + 10 - (n-pos) * 10)) {
            self(self, ar, pos + 1);
            ar[pos] += 1;
        }
    };
    next_per(next_per, a, 0);

    std::ostringstream output;
    output << ans.size() << "\n";
    for (auto &ai : ans) {
        for (auto &aii : ai) {
            output << aii << " ";
        }
        output << "\n";
    }
    cout << output.str();
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}