// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;

    if (n < 5) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i += 2) {
            if (i != 5) {
                cout <<i << " ";
            }
        }
        cout << "5 4 ";
        for (int i = 2; i <= n; i += 2) {
            if (i != 4 ) cout << i << " ";
        }
        cout << endl;
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