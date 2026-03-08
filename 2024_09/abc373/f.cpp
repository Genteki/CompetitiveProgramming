// f.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> w(n), v(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}