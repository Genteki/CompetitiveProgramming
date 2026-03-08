// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, ma = INT_MIN, mb = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ma = max(ma, x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mb = max(mb, x);
    }
    cout << (ma + mb);
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}