// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    int nl = k - 1;
    int nr = n - k;
    if (n == 1) {
        cout << 1 << endl << 1 << endl;
    }
    else if (nl % 2) {
        cout << 3 << endl;
        cout << 1 << " " << k << " " << k + 1 << endl;
    } else {
        if (nr == 0 || nl == 0) {
            cout << -1 << endl;
        } else {
            cout << 5 << endl;
            cout << 1 << " " << k - 1 << " " << k << " " << k + 1 << " " << k + 2  << endl; 
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