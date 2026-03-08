#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(), a.end());
    vector<int> b(3);
    for (int i = 0; i < 3; ++i) b[i] = bool(a[i+1] - a[i]);
    int s = accumulate(b.begin(), b.end(), 0);
    if (s == 1) {
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