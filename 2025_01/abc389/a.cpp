#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[2] - '0';
    cout << (a * b);
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