// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] * a[i+2] != a[i+1] * a[i+1]) {
            cout << "No";
            return;
        }
    }
    cout <<"Yes";
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