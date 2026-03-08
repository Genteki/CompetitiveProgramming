// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

int dvs[100005] = {0};
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    input(a);
    sort(all(a), std::greater());
    vector<int> ans(n + 1);
    ans[1] = 0;
    for (int i = 2; i <= n; ++i) {
        ans[i] = ans[dvs[i]] + 1;
        if (ans[i] >= m) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[ans[i]] << " ";
    cout << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    dvs[1] = 1;
    for (int i = 2; i <= 100000; ++i) {
        dvs[i] = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                dvs[i] = i/j;
                break;
            }
        }
    }
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}