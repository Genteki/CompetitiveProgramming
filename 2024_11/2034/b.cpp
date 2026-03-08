// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string  s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            cnt = 0;
        } else {
            cnt++;
        }
        if (cnt == m) {
            for (int j = i; j < min(n, i + k); j++) {
                s[j] = '1';
            }
            cnt = 0;
            ++ans;
        }
    }
    cout << ans << endl;
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