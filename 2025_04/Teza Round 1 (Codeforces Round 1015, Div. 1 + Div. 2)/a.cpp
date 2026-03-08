#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
        a[i] = i;
    }
    a[0] = n;
    if (n%2==0) cout << -1 ;
    else for (auto ai : a) cout << ai << " ";cout << endl;
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