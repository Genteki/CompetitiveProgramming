// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> diff(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        diff[i] = t[i] - s[i];
        cnt = cnt + (diff[i] != 0);
    }
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        if (diff[i] < 0) {
            s[i] = s[i] + diff[i];
            cout << s << endl;
        }
    }
    for (int i = n -1; i >= 0; --i) {
        if (diff[i] > 0) {
            s[i] = s[i] + diff[i];
            cout << s << endl;
        }
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}