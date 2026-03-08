#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    for (int i = 0; i < n-1; ++i) {
        if (a[i+1] <= a[i]) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}