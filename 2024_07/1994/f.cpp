// f.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), r(n);
    for (int i = 0; i < m; ++i) {
        int x, y, npc;
        cin >> x >> y >> npc;
        --x; --y;
        if (npc) {
            g[x].push_back(y);
            g[y].push_back(x);
        } else {
            r[x].push_back(y);
            r[y].push_back(x);
        }
    }

    

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