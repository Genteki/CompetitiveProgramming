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
    int n, m;
    cin >> n >> m;
    int theta = ceil(sqrt((double)m));
    vector<pair<int, int>> events(m);
    vector<vector<int>> person_event(n);
    vector<int> frequency(n, 0);
    vector<int> heavy;
    for (auto& [t, i] : events) {
        cin >> t >> i;
        --i;
        person_event[i].push_back(t);
        frequency[i]++;
    }
    for (int i = 0; i < n; ++i) {
        if (frequency[i] >= theta) {
            heavy.push_back(i);
        }
    }

    vector<vector<int>> heavy_result(heavy.size(), vector<int>(n, 0));
    vector<int> is_there(n, -1); 
    for (int i = 0; auto hi : heavy) {
        fill(all(is_there), -1);
        int timer = 0, last = 0;
        for (auto &[t, j] : events) {
            if (is_there[hi] != -1) {
                timer = timer + t - last;
            }
            if (is_there[j] == -1) is_there[j] = timer;
            else {
                heavy_result[i][j] += (timer - is_there[j]);
                is_there[j] = -1;
            }
            last = t;
        }
        ++i;
    }
    map<int, int> mp;
    for (int i = 0; i < heavy.size(); ++i) {
        mp[heavy[i]] = i;
    }

    int q;
    cin >> q;
    for (; q--;) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (mp.find(a) == mp.end() && mp.find(b) == mp.end()) {
            int timer = 0;
            bool exa = false, exb = false;
            int ia = 0, ib = 0;
            int ans = 0;
            debug(person_event[a]);
            debug(person_event[b]);
            while(ia + 1 < person_event[a].size()) {
                int start = person_event[a][ia];
                int end = person_event[a][ia + 1];
                ia += 2;
                timer = start;
                for (; ib < person_event[b].size() && person_event[b][ib] < end;
                     ++ib) {
                    exb = !exb;
                    if (exb == false && person_event[b][ib] > timer) {
                        ans += (person_event[b][ib] - timer);
                    } else {
                        timer = max(timer, person_event[b][ib]);
                    }
                }
                if (exb == true) {
                    ans += (end - timer);
                }
            }
            cout << ans << endl;
        } else {
            if (mp.find(a) == mp.end()) swap(a, b);
            cout << heavy_result[mp[a]][b] << endl;;
        }
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