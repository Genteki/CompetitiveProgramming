// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n)), b(m, vector<int>(n));
    for (auto & ai : a) input(ai);
    for (auto & bi : b) input(bi);

    if (m == 1 || n == 1) {
        cout << "YES" << endl;
        return;
    }
    vector<unordered_set<int>> rows(m), cols(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rows[i].insert(a[i][j]);
            cols[j].insert(a[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rows[j].find(b[i][0]) != rows[j].end()) {
                for (int k = 0; k < n; ++k) {
                    if (rows[j].find(b[i][k]) == rows[j].end()) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cols[j].find(b[0][i]) != cols[j].end()) {
                for (int k = 0; k < m; ++k) {
                    if (cols[j].find(b[k][i]) == cols[j].end()) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                break;
            }
        }
    }

    cout << "YES\n";
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