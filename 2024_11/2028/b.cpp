// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;

    if (a == 0) {
        if (b >= n) {
            cout << n << endl;
        } else if (b == n-1 || b == n-2) {
            cout << (n - 1) << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (b >= n) {
            cout << n << endl;
        } else {
            cout << (n - (n - 1 - b + a) / a) << endl;
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