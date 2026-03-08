// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto & ai : a) cin >> ai;
    sort(a.begin(), a.end());
    int idx = 0;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (idx < m and i == a[idx]) {
            ++idx;
        } else {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto ai : ans) cout << ai <<  " ";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}