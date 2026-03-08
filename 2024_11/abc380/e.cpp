#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for (auto &ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> s(n+1, 1); 
    map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        mp[i] = i;
    }
    mp[n] = n;
    while (q--) {
        int inst;
        cin >> inst;

        if (inst == 1) {
            int x, c;
            cin >> x >> c;
            --x; --c;

            auto it = mp.lower_bound(x); // Find the first segment that starts >= x

            if (it == mp.end()) continue; // Safety check

            if (it->first > x) --it; // Ensure `it` is pointing to the correct range

            int l = (next(it)->first) - (it->first); // Length of current segment
            s[it->second] -= l;                     // Decrease count for current color
            s[c] += l;                              // Increase count for new color

            it->second = c; // Change the color of the current segment to c

            // Merge subsequent segments with the same color
            while (next(it) != mp.end() && next(it)->second == c) {
                auto tmp = next(it);
                mp.erase(tmp);
            }

            // Merge previous segments with the same color
            while (it != mp.begin() && prev(it)->second == c) {
                auto tmp = prev(it);
                mp.erase(it);
                it = tmp;
            }
        } else {
            int c;
            cin >> c;
            --c; // Convert to 0-based indexing

            cout << s[c] << endl; // Output the count of cells painted with color c
        }
        #ifdef LOCAL
        auto x = vector<pair<int,int>>(all(mp));
        debug(x);
        debug(s);
        #endif
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}