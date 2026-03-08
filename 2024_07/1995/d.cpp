#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'A';
    }
    vector<vector<int>> ps(n+1, vector<int>(c, 0));
    vector<bool> masks((1 << c), 0);
    
    for (int i = 0; i < n; ++i) {
        ps[i+1] = ps[i];
        ps[i+1][a[i]]++;
    }

    for (int i = 0; i < n - k; ++i) {
        int mask = 0;
        for (int j = 0; j < c; ++j) {
            if (ps[i+k][j] - ps[i][j]) mask |= (1 << j);
        }
        masks[mask] = true;
    }
    masks[1 << a.back()] = true;

    // for (auto badi : masks) cout << badi << " ";
    // cout << endl;


    vector<bool> bad((1<<c), 0);
    for (int bad_mask = 0; bad_mask < (1 << c); ++bad_mask) {
        bad[bad_mask] = masks[((1<<c)-1) ^ bad_mask];
    }

    // for (auto badi : bad) cout << badi << " "; cout << endl;

    for (int mask = (1 << c) - 1; mask >= 0; --mask) {
        for (int i = 0; i < c; ++i) {
            bad[mask] = bad[mask | (1 << i)] | bad[mask];
        }
    }
    // for (auto badi : bad) cout << badi << " ";
    // cout << endl;

    int ans = 30;
    for (int i = 0; i < (1 << c); ++i) {
        if (!bad[i]) ans = min(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}