#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int a, b;
    cin >> a >> b;
    if ( a==b ) {
        cout << 1 << endl;
    } else if (!((a % 2) ^ (b % 2))) {
        cout << 3 << endl;
    } else {
        cout << 2 << endl;
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