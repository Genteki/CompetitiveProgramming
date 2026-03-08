//;Bellman-Ford Algorithm¶

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
const long long inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, i64>>> g(n);
    for (;m--;) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        g[x].emplace_back(y, z);
    }

    queue<int> q;
    vector<bool> in_queue(n, false);
    vector<int> cnt(n, 0);
    vector<i64> d(n, -inf);
    in_queue[0] = true;
    q.push(0);
    d[0] = 0;

    vector<bool> viewed(n, false);
    auto f = [&](auto&&self, int node) -> void {
        viewed[node] = true;
        cnt[node] = n+1;
        for (auto [to, len] : g[node]) {
            if (!viewed[to]) {
                self(self, to);
            }
        }
    };

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        in_queue[v] = false;
        for (auto [to, len] : g[v]) {
            if (d[to] < (d[v] + len) && cnt[to] <= n) {
                d[to] = d[v] + len;
                if (!in_queue[to]) {
                    q.push(to);
                    cnt[to]++;
                    if (cnt[to] > n) {
                        f(f, to);
                    }
                }
            }
        }
    }
    if (d[n-1]==-inf || cnt[n-1] > n) cout << -1;
    else cout << d[n-1];
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