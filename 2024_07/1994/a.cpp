#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto & ai : a) {
        input(ai);
    }

    if (m == 1 && n == 1) {
        cout << "-1" << endl;
        return;
    }
    if (m == 1) {
        int tmp = a[0][0];
        for (int i = 0; i < n-1; ++i) {
            a[i][0] = a[i+1][0];
        }
        a[n-1][0] = tmp;
        for (auto ai : a) {
            for (auto aii : ai) {
                cout << aii << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        int tmp = a[i][0];
        for (int j = 0; j < m-1; ++j) {
            a[i][j] = a[i][j+1];
        }
        a[i][m-1] = tmp;
    }
    for (auto ai : a) {
        for (auto aii : ai) {
            cout << aii << " ";
        }
        cout << endl;
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