#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int a,b;
    cin >> a >> b;
    cout << (i64)pow(a+b, 2);
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