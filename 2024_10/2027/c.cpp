// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    reverse(all(a));
    map<i64,vector<i64>> mp;
    for (int i = 0; i < n - 1; ++i) {
        a[i] = a[i] - 1 - i;
        if (a[i] >= 0) {
            mp[a[i]].push_back(n - 1 - i);
        }
    }
    debug(vector<pair<i64,vector<i64>>>(all(mp)));
    debug(1);
    set<i64> ans;
    queue<i64> q;
    q.push(0);
    while(!q.empty()) {
        i64 u = q.front();
        debug(u);
        q.pop();
        for (i64 v : mp[u]) {
            i64 nv = v + u;
            if (ans.find(nv) == ans.end()) {
                ans.insert(nv);
                q.push(nv);
            }
        }
    }
    i64 x = ans.empty()? 0 :  *ans.rbegin();
    cout << (x + n) << endl;
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