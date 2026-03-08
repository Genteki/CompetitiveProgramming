// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nest(n);
    std::iota(nest.begin(), nest.end(), 0);
    vector<int> cnt(n, 1);
    int ans = 0;
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, h;
            cin >> p >> h;
            --p; --h;
            cnt[nest[p]]--;
            if (cnt[nest[p]] == 1) {
                --ans;
            }
            cnt[h]++;
            if (cnt[h] == 2) {
                ++ans;
            }
            nest[p] = h;
        } else {
            cout << ans << endl;
        }
    }
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