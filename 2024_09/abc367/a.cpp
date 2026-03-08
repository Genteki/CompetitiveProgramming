#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() { 
    int a, b, c;
    cin >> a >> b >> c;
    if (b < c) {
        if (a > b && a < c) {
            cout << "No";
        } else {
            cout << "Yes";
        }
    } else {
        if (a > c && a < b) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
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