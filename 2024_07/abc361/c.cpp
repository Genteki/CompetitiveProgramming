// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    input(a);
    int ans = INT_MAX;
    sort(all(a));
    for (int i = 0;i <=k; ++i) {
        int d = a[n-1-i] - a[k-i];
        ans = min(ans, d);
    }
    cout << ans;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}