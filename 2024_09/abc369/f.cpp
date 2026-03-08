// f.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> m(h);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        m[x].push_back(y);
    }
    for (auto & mi : m) {
        sort(all(mi));
    }
    map<int, pair<int, int>> mp;
    mp[0] = {0, 0};
    for (int i = 0; i < m[0].size(); ++i) {
        mp[m[0][i]] = {i + 1, 0};
    }

    for (int i = 1; i < h; ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            auto it = mp.upper_bound(m[i][j]);
            it = prev(it);
            mp[m[i][j]] = {(it->second).first + 1, i};
            // i64 previ = (it->second).first * w + (it->);

            it = mp.find(m[i][j]);
            int cur = (it -> second).first;
            vector<int> to_remove;
            while(next(it) != mp.end() && (next(it) -> second).first < cur) {
                it = next(it);
                to_remove.push_back(it->first);
            }
            for (auto ti : to_remove) {
                mp.erase(ti);
            }
        }
    }

    debug(mp);
    std::cout << rbegin(mp)->second.first << endl;
    string ans = "";
    vector<pair<int,int>> path;
    path.emplace_back(h-1, w-1);
    int cur_val = rbegin(mp)->second.first;
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        int j = it -> first;
        int i = it -> second.second;
        int val = it -> second.first;
        if (i <= path.back().first && j <= path.back().second) {
            path.emplace_back(i, j);
        }
    }
    path.emplace_back(0,0);
    reverse(all(path));
    debug(path);
    for (int i = 0; i < path.size()-1; ++i) {
        ans += string(path[i + 1].second - path[i].second, 'R');
        ans += string(path[i + 1].first - path[i].first, 'D');
    }
    std::cout << ans << endl;
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