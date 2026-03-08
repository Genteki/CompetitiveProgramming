#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "fine" and s2 == "fine") {
        cout << 4;
    } else if (s1 == "sick" and s2 == "sick") {
        cout << 1;
    } else if (s1 == "fine") {
        cout << 3;
    } else {
        cout << 2;
    }
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