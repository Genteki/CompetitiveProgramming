// 1662c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> vc;
    for (int i = 0; i < k; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        if (u > v) swap(u,v);
        vc.emplace_back(u,v);

    }   
    i64 ans = (n-k-1 + 0) *(n-k) / 2;
    i64 ans2 = 0;
    for (auto [u, v] : vc) {
        int cnt = v - u - 1;
        for (auto [ui, vi] : vc) {
            bool f1, f2;
            if (ui < v and ui > u) {
                --cnt;
                f1 = true;
            } else {
                f1 = false;
            }
            if (vi < v and vi > u) {
                --cnt;
                f2 = true;
            } else {
                f2 = false;
            }
            if (f1 ^ f2) ++ans2;
        }
        ans += min(cnt, (n-k)*2-cnt);
    }
    cout << (ans + ans2/2) << endl;

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