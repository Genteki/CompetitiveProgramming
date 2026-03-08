// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        a[i] = i % 2;
    }
    int bias = 0;
   if (n % 2== 1) {
    a[n-1] = 2;
    bias = n-1-x;
   } else {
    if (a[x] == a[y]) {
        a[x] = 2;
    }
   }
    for (int i = 0; i <n;++i)
        cout << a[(i+bias)%n] << " ";
        cout << endl;
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