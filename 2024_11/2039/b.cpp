// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << -1 << endl;
    } else if (n == 2) {
        if (s[0] == s[1]) {
            cout << s << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        for (int i = 0; i < n -1; ++i) {
            if (s[i] == s[i + 1]) {
                cout << s.substr(i, 2) << endl;
                return;
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
                cout << s.substr(i, 3) << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
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