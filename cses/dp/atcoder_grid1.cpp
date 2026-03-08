// Grid 1
// https://atcoder.jp/contests/dp/tasks/dp_h
// DP

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
const i64 mod = 1e9 + 7;
void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> m(h, vector<char>(w));
    for (auto & mi : m) {
        for (auto & mii : mi) {
            cin >> mii;
        }
    }

    vector<vector<i64>> ans(h, vector<i64>(w, 0));
    ans[0][0] = 1;
    for(int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == '#') continue;
            if (i>=1) {
                ans[i][j] += ans[i-1][j];
            }
            if (j >= 1) {
                ans[i][j] += ans[i][j-1];
            }
            ans[i][j] %= mod;
        }
    }
    cout << ans.back().back() << endl;
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