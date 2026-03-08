// atcoder_stones.cpp
// https://atcoder.jp/contests/dp/tasks/dp_k
// DP

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    input(a);
    sort(all(a));
    vector<int> dp(k + 1, 0);
    dp[0] = 0;
    bool winner = 1;
    for (int i = 0; i <= k; ++i) {
        for (auto ai : a) {
            if (i-ai < 0) break;
            if (dp[i-ai] == 0) {
                dp[i] = 1;
            }
        }
    }
    if (dp[k] == 0) cout << "Second\n";
    else cout << "First\n";
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