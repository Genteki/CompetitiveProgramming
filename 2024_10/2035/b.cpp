// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 0) {
        for (int i = 0; i < (n / 2 - 1); ++i) {
            cout << "33";
        } cout << "66" << endl;
    } else {
        for (int i = 0; i < (n - 5) / 2; ++i) {
            cout << "33";
        } 
        cout << "36366" << endl;
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