// dp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

constexpr i64 mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> a;
    for (auto & ai : a) {
        for (auto & aii : ai) {
            cin >> aii;
        }
    }
    vector<vector<i64>> ans(n, vector<i64>(-1));
    ans[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        
    }
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