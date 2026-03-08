#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

struct Edge {
    i64 c, l, r;
    Edge(const i64& ic = 0, const i64& il = 0, const i64& ir = 0)
        : c(ic), l(il), r(ir) {}
    bool operator<(const Edge& other) { return (this->c < other.c); }
};

void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<Edge> edge(q);
    for (auto & ei : edge) {
        cin >> ei.l >> ei.r >> ei.c;
    }
    sort(all(edge));
    vector<i64> a(n);
    for (int i = 0; auto & ai : a) ai = (++i);
    set<i64> s(all(a));
    i64 ans = 0;
    for (auto & ei : edge) {
        auto it_left = s.upper_bound(ei.l);  // q log n
        auto it_right = s.upper_bound(ei.r);   // q log n
        i64 d = distance(it_left, it_right);
        // n log n
        if (it_left != s.end() && it_left != it_right) {
            s.erase(it_left, it_right);
        }
        ans += (ei.c * (1 + d));
    }
    // debug(ans);
    if(s.size() == 1) cout <<(ans);
    else cout << -1;
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