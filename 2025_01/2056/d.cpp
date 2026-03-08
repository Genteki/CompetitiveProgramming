// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef __int128_t i128;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    vector<int> b(n);

    for (int k = 1; k <= 10; ++k) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == k) {
                b[i] = 0;
            } else if (a[i] < k) {
                b[i] = -1;
            } else {
                b[i] = 1;
            }
        }
        
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