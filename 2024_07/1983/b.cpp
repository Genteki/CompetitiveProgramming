#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    char c;
    for (auto& ai : a) {
        for (auto& aii : ai) {
            cin >> c;
            aii = c - '0';
        }
    }
    for (auto& ai : b) {
        for (auto& aii : ai) {
            cin >> c;
            aii = c - '0';
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int d = b[i][j] + 3 - a[i][j];
            a[i][j] = b[i][j];
            a[i + 1][j + 1] = (a[i + 1][j + 1] + d) % 3;
            a[i + 1][j] = (a[i + 1][j] + d * 2) % 3;
            a[i][j + 1] = (a[i][j + 1] + d * 2) % 3;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i][m - 1] != b[i][m - 1]) {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (a[n - 1][i] != b[n - 1][i]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}