// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int x;
    cin >> x;
    int ans=0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9;++j) {
            if (i*j!= x){
                ans += (i*j);
            }
        }
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