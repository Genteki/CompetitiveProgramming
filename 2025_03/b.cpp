// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n, '.'));
    for (int i = 0; i < n; ++i) {
        int j = n - 1 - i;
        if (i > j) continue;
        char c = i%2?'.':'#';
        for (int k = i; k <= j; ++k) {
            for (int l = i; l <= j; ++l) {
                a[k][l] = c;
            }
        }
    }
    for (auto ai : a) {
        for (auto aii : ai) {
            cout << string(1, aii);
        } cout << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}