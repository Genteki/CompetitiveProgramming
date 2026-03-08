// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,m;
    cin >> n>> m;
    vector<set<int>> g(n*m);
    for (int i = 0; i < n*m; ++i) {
        int c;
        cin >> c;
        --c;
        g[c].insert(i);
    }
    int ans = 0, q=0;
    for (auto & gi : g) {
        if (gi.empty()) continue;
        int f = 1;
        for (auto pos : gi) {
            if (((pos+1)%m==0 or gi.find(pos+1) == gi.end()) and gi.find(pos+m) == gi.end()) {
                continue;
            } else {
                f = 2;
            }
            cerr<<(pos)<<f<<endl;
        }
        ans += f;
        q = max(q, f);
    }
    cout << (ans-q) << endl;
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