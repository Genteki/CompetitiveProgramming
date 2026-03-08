// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = (s[i] == '1');
    queue<i64> q; i64 ans = 0;
    for (int i = n - 1; i>= 0; --i) {
        if (a[i] == 1) {
            q.push(i);
        } else {
            if (q.empty()) {
                ans += (i + 1);
            } else {
                q.pop();
                ans += (i + 1);
            }
        }
    }
    vector<i64> r;
    while(!q.empty()) {
        r.push_back(q.front());
        q.pop();
    }
    reverse(all(r));
    for (int i = 0; i < (r.size() + 1) / 2; ++i) {
        ans += (r[i] + 1);
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