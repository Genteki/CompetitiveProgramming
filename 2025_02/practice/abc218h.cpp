#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    vector<int> a(n, 0);
    for (int i = 0; i < n-1; ++i) cin >> a[i];
    
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