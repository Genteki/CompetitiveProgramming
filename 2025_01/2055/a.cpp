#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a-b)%2==0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
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