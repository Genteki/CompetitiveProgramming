#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    bool flag = true;
    if (n == 1) {
        if (s[0] == 'Y' or s[0] == 'e' or s[0] == 's') {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == 'Y' and s[i+1] =='e') {

        } else if (s[i] == 'e' and s[i+1] == 's') {}
        else if (s[i] == 's' and s[i+1] == 'Y') {}
        else {
            flag = false;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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