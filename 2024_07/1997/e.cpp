#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> ps(n+1, vector<int>(1000, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1000; ++j) {
            ps[i+1][j] = ps[i][j] + (a[i])
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}