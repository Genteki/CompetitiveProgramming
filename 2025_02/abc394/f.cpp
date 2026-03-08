// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug2.h"
#else
#define debug(...)
#endif
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector g(n, set<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].insert(v);
        g[v].insert(u);
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= 4) {
            ans = 0;
            break;
        }
    }
    if (ans < 0) {
        cout << -1;
        return;
    }

    vector<array<int,4>> dp(n);
    vector<int> s(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>> > pq;
    for (int i = 0; i < n; ++i) {
        if (g[i].size()==1) {
            pq.emplace(1, i); 
            //C
        }
    }
    
    auto srt = [](array<int,4>& x) -> void{sort(x.begin(), x.end(), greater());};
    int ns = n;
    debug(dp);
    while(!pq.empty()) {
        auto [sz, u] = pq.top();
        pq.pop();
        srt(dp[u]);
        int upd = 1;
        if (dp[u][2] == 0) {
            upd = 1;
        } else {
            upd = accumulate(dp[u].begin(), dp[u].begin()+3, 1);
        }
        chmax(ans, dp[u][0] + 1);

        if (!g[u].empty()) {
            auto v = *g[u].begin();
            chmax(dp[v][3], upd);
            srt(dp[v]);
            g[u].clear();
            --ns;
            g[v].erase(u);
            if (g[v].size() == 1) {
                pq.emplace(accumulate(dp[v].begin(), dp[v].begin()+3,0)+1, v);
            }
            chmax(ans, upd+1);
        } else {
            if (dp[u][3] == 0) {
                chmax(ans, dp[u][0] + 1);
            } else {
                chmax(ans, accumulate(dp[u].begin(), dp[u].end(), 1));
            }
        }
        debug(u, dp[u]);
    }
    debug(dp);
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}