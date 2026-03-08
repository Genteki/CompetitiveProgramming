#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> cards,s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cards.push_back(x);
        s.push_back(0);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cards.push_back(x);
        s.push_back(1);
    }
    for (int i = 0; i < l; ++i) {
        int x;
        cin >> x;
        cards.push_back(x);
        s.push_back(2);
    }
    int k = n + m + l;
    auto hash = [](const vector<int>&states, bool player) -> int {
        int x = 0;
        for (int i = 0; i < states.size(); ++i) {
            x |= (states[i] << (i * 2));
        }
        if (player) x = -x;
        return x;
    };
    map<int, bool> memo;
    auto dfs = [&](auto && self, vector<int> &states, bool player) -> bool {
        bool win = false;
        int x = hash(states, player);
        if (memo.find(x) != memo.end()) return memo[x];
        for (int i = 0; i < k; ++i) {
            if (states[i] == player) {
                states[i] = 2;
                win |= (!self(self, states, !player));
                for (int j = 0; j < k; ++j) {
                    if (states[j] == 2 && cards[j] < cards[i]) {
                        states[j] = player;
                        win |= (!self(self, states, !player));
                        states[j] = 2;
                    }
                }
                states[i] = player;
            }
        }
        memo[x] = win;

        return win;
    };
    bool ans = dfs(dfs, s, 0);
    if (ans ) {
        cout << "Takahashi";
    } else {
        cout << "Aoki";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}