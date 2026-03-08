// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> st1, st2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        st1[a[i]]++;
    }
    int ans = st1.size();
    for (int i = 0; i < n; ++i) {
        st1[a[i]]--;
        st2[a[i]]++;
        if (st1[a[i]] == 0) st1.erase(a[i]);
        ans = max<int>(ans, st1.size() + st2.size());
    }
    cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}