#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<vector<int>> g(n);
    i64 dmg = 0;
    for (int i = 0; i < n -1; ++i) {
        int x,y;
        cin >> x>> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<i64> s(n, 0), subtree_s(n, 0);

    auto remove = [&](auto&& self, int node, int parent = -1) -> void {
        if (g[node].size() == 1 && g[node][0] == parent) {
            a[node] = 0;
            return;
        }
        if (s[node] < subtree_s[node]) {
            for (auto to : g[node]) {
                if (to == parent) continue;
                self(self, to, node);
            }
        } else {
            a[node] = 0;
            for (auto to : g[node]) {
                if (to == parent) continue;
                for (auto too : g[to]) {
                    if (too == node) continue;
                    self(self, too, to);
                    // cout << "x" << too << " ";
                }
            }
        }
    };

    auto f = [&](auto&& self, int node, int parent=-1) -> void {
        if (g[node].size()==1 && g[node][0]==parent) {
            s[node] = a[node];
            return;
        }
        i64 s1 = 0, s2 = a[node];
        for (int to : g[node]) {
            if (to == parent) continue;
            self(self, to, node);
            s1 += max(s[to], subtree_s[to]);
            s2 += subtree_s[to];
        }
        
        subtree_s[node] = s1;
        s[node] = s2;
    };

    i64 tmp = accumulate(all(a), 0LL);
    while(tmp) {
        dmg += tmp;
        f(f, 0);
        remove(remove, 0);
        tmp = accumulate(all(a), 0LL);
        fill(all(s), 0LL);
        fill(all(subtree_s), 0LL);
    }


    cout << dmg << endl;
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