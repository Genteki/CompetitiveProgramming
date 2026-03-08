#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    input(a);
    bool ans = 0, idx = -1;
    for (int i = 0; i < n; ++i) {
        bool win = true;

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                if (abs(a[j] - a[i]) % k == 0) {
                    win = false;
                }
            }
            
        }
        if (win) {
            cout << "YES\n" << (i + 1) << endl;
            return;
        }
    }
    cout << "NO\n";
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