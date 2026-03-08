// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n - 1);
    input(a);
    i64 x;
    cin >> x;
    i64 ans = 0 ;
    x -= a.back();
    for (int i = 0; i < n-2; ++i) x+=a[i];
    cout << x<< endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}