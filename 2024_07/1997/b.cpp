#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> b(2, vector<char>(n));
    vector<vector<bool>> used(2, vector<bool>(n, false));
    input(b[0]);
    input(b[1]);

    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;
    auto a = b;
    for (int i = 1; i < n-1; ++i) {
        if (a[0][i] == '.' && a[0][i-1] == '.' && a[0][i+1] == '.' && a[1][i] == '.' && a[1][i-1] =='x' && a[1][i+1] =='x') {
            ++ans;
        }
        if (a[1][i] == '.' && a[1][i - 1] == '.' && a[1][i + 1] == '.' &&
            a[0][i] == '.' && a[0][i - 1] == 'x' && a[0][i + 1] == 'x') {
            ++ans;
        }
    }
    cout << ans << endl;
    // cout << ans << endl;

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