// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n; cin >> n;
    vector<vector<pair<i64, i64>>> g(n);
    i64 d = 0;
    for (i64 i = 0; i < n-1; ++i) {
        i64 a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        d += (c * 2);
    }
    auto lp = [&](auto&& self, i64 node, i64 p = -1) -> pair<i64, i64> {
        i64 l = 0LL, m = 0LL;
        if(g[node].size() == 1 && g[node][0].first==p) {
            // cout << "empty" << endl;
            return make_pair(0LL, 0LL);
        }
        priority_queue<i64> pq;
        pq.push(0LL);
        for (auto & [to, dto] : g[node]) {
            if (to == p) continue;
            auto [tol, tom] = self(self, to, node);
            pq.push(tol + dto);
            m = max(tom, m);
            l = max(l, tol+dto);
        }

        i64 this_m = 0;
        this_m += pq.top();
        pq.pop();

        this_m += pq.top();
        m = max(this_m, m);
        return {l, m};
        
    };
    priority_queue<i64> pq;
    i64 dia = lp(lp, 0, -1).second;
    cout << (d-dia) << endl;
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