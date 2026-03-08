// g.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 h, w, k;
    cin >> h >> w >> k;
    i64 si, sj;
    cin >> si >> sj;
    --si; --sj;

    vector<vector<i64>> a(h, vector<i64>(w));

    for (auto & ai : a) {
        input(ai);
    }

    vector<vector<vector<i64>>> dp(2, vector<vector<i64>>(h, vector<i64>(w, -1)));
    i64 directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    dp[0][si][sj] = 0;
    i64 steps = min(k, 4 * h * w);

    for (i64 i = 0; i < steps; ++i) {
        i64 cur = 1 - (i % 2);
        i64 prev = 1 - cur;
        for (i64 j = 0; j < h; ++j) {
            for (i64 k = 0; k < w; ++k) {
                
                if (dp[prev][j][k] != -1) dp[cur][j][k] =dp[prev][j][k] + a[j][k];
                for (auto & dir : directions) {
                    i64 prevj = j - dir[0];
                    i64 prevk = k - dir[1];
                    if (prevj >= 0 && prevj < h && prevk >=0 && prevk < w) {
                        if (dp[prev][prevj][prevk] >= 0) {
                            dp[cur][j][k] = max(dp[cur][j][k], dp[prev][prevj][prevk] + a[j][k]);
                        }
                    }
                }
            }
        }
        // for (i64 j = 0; j < h ; ++j) {
        //     for (i64 k = 0; k < w; ++k) {
        //         cout << dp[cur][j][k] << " ";
        //     }cout << endl;
        // }
    }
    i64 ed = steps % 2;
    i64 ans= 0;
    int cur_i = -10;
    int cur_j = -10;
    for (i64 i = 0; i < h; ++i) {
        for (i64 j = 0; j < w; ++j) {
            
            if (ans < dp[ed][i][j]) {
                cur_i = i;
                cur_j = j;
            } else if (ans == dp[ed][i][j] && a[i][j] > a[cur_i][cur_j]) {
                cur_i=i;
                cur_j=j;
            }
            ans = max(ans, dp[ed][i][j]);
        }
    }
    int mi = -1, mj = -1;
    if (k > steps) {
        i64 m_cell = 0;
        for (i64 i =0; i < h; ++i) {
            for (i64 j = 0; j < w; ++j) {
                if(m_cell < a[i][j]) {
                    mi = i;
                    mj = j;
                }
                m_cell = max(m_cell, (i64)a[i][j]);

            }
        }
        // ans += ((k-steps) * m_cell);
        i64 ans1 = ans + a[cur_i][cur_j] * (k-steps);
        i64 ans2 = dp[ed][mi][mj] + a[mi][mj] * (k-steps);
        ans = max(ans1, ans2);
    }

    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}