// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    vector<pair<i64, i64>> s;
    i64 ans = 0;
    for(i64 i = 0; i < n; ++i) {
        i64 x, y;
        cin >> x >> y;
        i64 r = 0;
        while (!s.empty() && !(s.back().second != y && x < s.back().first)) {
            if (s.back().second == y) {
                x = x + s.back().first - r;
                r = 0;
                s.pop_back();
            } else if (s.back().first <= x && s.back().second != y) {
                r = max<i64>(r, s.back().first);
                s.pop_back();
            }
        }
        if (s.empty() || s.back().first > x ) s.emplace_back(x , y);

        ans = max<i64>(ans, s.back().first);
        cout << ans << " ";
    }
    cout << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
