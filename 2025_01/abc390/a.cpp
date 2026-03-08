#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n = 5;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        if (a[i] > a[i + 1]){swap(a[i], a[i+1]); ++cnt;}
        
    }
    if (cnt == 1) cout << "Yes";
    else cout << "No";
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