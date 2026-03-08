// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(m), q(k);
    for (auto & ai : a) cin >> ai;
    for (auto& ai : q) cin >> ai;

    vector<int> ans(m, 0);
    if (k == n-1) {
        int t = k;
        for (int i = 0; i < k; ++i) {
            if (q[i] != i + 1) {
                t = i;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (a[j] == (t + 1)) {
                ans[j] = 1;
            }
        }
    } else if (k == n) {
        fill(ans.begin(), ans.end(), 1);
    }
    for (auto ai : ans)  cout << ai;
    cout << endl;

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