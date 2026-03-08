// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1&&m==2) {
        cout << "NO" << endl;
        return;
    }
    vector g(n * 2, vector<int>(n * 2, 0));
    if (m >= n * 2) {cout << "NO" << endl;return;}
    int p = 0;
    for (int i = 0; i < n*2; ++i) {
        // if (i < n) g[0][i] = i + 1;
        // if (i >= n) g[0][i] = 2 * n - i;
        g[0][i] = 1 + (i/2);
    }
    for (int i = 1; i < n * 2; ++i) {
        for (int j = 0; j < n * 2; ++j) {
            g[i][j] = g[i - 1][(j - 1 + n * 2) % (n * 2)];
        }
    }

    cout << "YES\n";

    for (auto &gi : g) {
        for (int j = 0; j < m; ++j) {
            cout << gi[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}