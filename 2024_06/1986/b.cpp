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
    vector<vector<int>> a(m, vector<int>(n));
    for (auto & ai : a) 
        for (auto & aii : ai) 
            cin >> aii;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int y = 0;
            if (i + 1 < m) {
                // x = min(x, a[i+1][j]);
                y = max(y, a[i+1][j]);
            }
            if (j + 1 < n) {
                // x = min(x, a[i][j + 1]);
                y = max(y, a[i][j + 1]);
            }
            if (i - 1 >= 0) {
                // x = min(x, a[i - 1][j]);
                y = max(y, a[i - 1][j]);
            }
            if (j - 1 >= 0) {
                // x = min(x, a[i][j - 1]);
                y = max(y, a[i][j - 1]);
            }
            // cout << " " << a[i][j] << "," << y << " ";
            a[i][j] = min(a[i][j], y);
        }
    }

    for (auto & ai : a) {
        for (auto & aii : ai) {
            cout << aii << " ";
        } cout << endl;
    }
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