// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
typedef long long i64;
using tuple3 = array<i64, 3>;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> ans(n, 0);
    vector<array<i64, 3>> p(n);
    vector<array<i64, 3>> q(n);
    for (i64 i = 0; i < n; ++i) {
        p[i][0] = i;
        cin >> p[i][1] >> p[i][2];
        q[i] = p[i];
    }
    auto comp1 = [](tuple3 &a, tuple3 &b) -> bool { 
        if (a[1] != b[1])
            return a[1] < b[1];
        else 
            return a[2] > b[2]; 
    };
    auto comp2 = [](tuple3 &a, tuple3 &b) -> bool {
        if (a[2] != b[2])
            return a[2] > b[2];
        else
            return a[1] < b[1];
    };
    sort(all(p), comp1);

    set<i64> s;
    for (i64 i = 0; i < n; ++i) {
        auto [idx, l, r] = p[i];
        auto it = s.lower_bound(r);
        if (it == s.end()) {
            // continue;
        } else {
            ans[idx] += (*it - r);
        }

        s.insert(r);
    }
    sort(all(p), comp2);
    s = set<i64>();
    for (i64 i = 0; i < n; ++i) {
        auto [idx, l, r] = p[i];
        auto it = s.upper_bound(l);

        if (it == s.begin()) {
            // continue;
        } else {
            ans[idx] += (l - *(--it));
        }
        s.insert(l);
    }
    for (i64 i = 0; i < n-1; ++i) {
        if (p[i][1] == p[i+1][1] && p[i][2] == p[i+1][2]) {
            ans[p[i][0]] = 0;
            ans[p[i+1][0]] = 0;
        }
    }
    for (auto ai : ans) cout << ai << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}