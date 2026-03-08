// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    if (n == 6) {
        ans = { 1, 1, 2, 3, 1 ,2 };
    }
    else if (n % 2 == 1) {
        for (int i = 0; i < n/2; ++i) {
            ans[i] = i + 1;
            ans[n/2+i+1] = i + 1;
        }
        ans[n/2] = n/2+1;
    } else {
        for (int i = 0; i < n / 2; ++i) {
            ans[i] = i + 1;
            ans[n / 2 + i] = i + 1;
        }
    }

    for (int ai : ans) cout << ai << " ";
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