#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    i64 e = 0;
    i64 ans = 0;
    for(auto& ai : a) {
        cin >> ai;
        if (ai % 2 == 1) {
            ans++;
        } else {
            e++;
        }
    }
    if (e) {
        cout << (1 + n - e) << endl;
    } else {
        cout << max(n-1, 0) << endl;
    }

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