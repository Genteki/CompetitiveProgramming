// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    i64 mod = 998244353;
    double ans = 1;
    double p = double(n-1)*(n-1)/(n*n);
    for (int i = 0; i < k; ++i) {
        ans = ans * p;
    }
    ans = (1-ans) * (.5 + n / 2.0) + ans;
    double x = ans * mod / n;
    cout << x ;
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