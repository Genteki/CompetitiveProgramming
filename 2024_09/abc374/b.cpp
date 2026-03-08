// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s.size() > t.size()) swap(s, t);
    int l1 = s.size(), l2 = t.size();
    int ans = 0;
    for (int i = 0; i < l1; ++i) {
        if (s[i] != t[i]) {
            cout << (i + 1) << endl;
            return;
        }
    }
    if (l2 > l1) {
        cout << (l1 + 1) << endl;
    } else {
        cout << 0 << endl;
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