// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, d;
    cin >> n >> d;
    set<int> ans = {1};
    if (d % 5==0) {
        ans.insert(5);
    }
    if (d%7==0) ans.insert(7);
    if (d % 3 == 0) ans.insert(3);
    if (d % 9 == 0) ans.insert(9);

    if (n >= 3) {
        if (ans.find(3) != ans.end()) ans.insert(9);
        else ans.insert(3);
        ans.insert(7);
    }
    if (n >= 6) {
        ans.insert(9);
        ans.insert(3);
    }
    for (auto ai : ans) cout << ai << " ";
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