#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if(a[0] + a[1] == a[2] or (a[0] == a[1] and a[1] == a[2])) {
        cout << "Yes";
    } else {
        cout << "No";
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