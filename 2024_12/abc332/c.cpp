// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 0, logo = 0, p = 0;
    for (auto si : s) {
        if (si == '0') {
            logo = 0;
            p = 0;
        } else if (si == '2') {
            ++logo;
        } else {
            if (p < m) ++p;
            else ++logo;
        }
        ans = max(ans, logo);
    }
    cout << ans;
    
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}