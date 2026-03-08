#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
constexpr long long inf = __LONG_LONG_MAX__;
typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
        // g[y].push_back(x);
    }
    i64 ans = 0;

    auto f = [&](auto&& self, int node) -> vector<i64> {
        if (g[node].empty()) {
            return {inf};
        }
        // calcuate thing to subtract
        i64 order = a[node];
        for (int& to : g[node]) {
            order -= a[to];
        }
        // calculate rest
        auto rest = self(self, g[node][0]);
        for (int i = 1; i < g[node].size(); ++i) {
            auto restt = self(self, g[node][i]);
            if (rest.size() > restt.size()) {
                swap(rest, restt);
            }
            int d = restt.size() - rest.size();
            for (int j = 0; j < rest.size(); ++j) {
                if (rest[j] == inf) continue;
                rest[j] += restt[j + d];
            }
        }

        if (order > 0) {
            for (int i = rest.size() - 1; i >= 0; --i) {
                i64& ri = rest[i];
                ans += order;
                if (ri < order) {
                    order -= ri;
                    ri = 0;
                } else {
                    if (ri == inf) {
                        break;
                    }
                    ri -= order;
                    order = 0;
                    break;
                }
            }
            rest.push_back(0);
        } else {
            rest.push_back(-order);
        }

        return rest;
    };

    f(f, 0);
    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}