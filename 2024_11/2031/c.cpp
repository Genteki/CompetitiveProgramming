// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
void solve() {
    int n;
    cin >> n;

    if (n % 2 == 1 && n < 27) {
        cout << -1 << endl;
        return;
    } 
    int cnt = 1;
    int up = n;
    vector<int> ans(n, 0);
    if (n % 2) {
        ans[0] = 1;
        ans[9] = 1;
        ans[25] = 1;
        ans[26] = 2;
        ans[10] = 2; 
        cnt += 2;
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            ans[i] = cnt;
            ans[i + 1] = cnt;
            cnt++;
        }
    }
    for (auto ai : ans) cout << ai << " ";
    cout << endl;
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