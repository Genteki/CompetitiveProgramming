#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f;  // memset(a, 0x3f, sizeof(a))

void solve() {
    int m, n;
    cin >> n >> m;
    vector<unordered_set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    stack<int> st;
    vector<int> ans;
    // judge whether solution is impossible
    vector<int> odd_deg;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() % 2 == 1) odd_deg.push_back(i);
    }

    if (odd_deg.size() != 0 || g[0].size() == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    st.push(0);

    while (!st.empty()) {
        int v = st.top();
        if (g[v].empty()) {
            st.pop();
            ans.push_back(v);
        } else {
            int u = *g[v].begin();
            st.push(u);
            g[u].erase(v);
            g[v].erase(u);
        }
    }
    // ans.push_back(0);
    if (ans.size()-1 != m) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    // cout << m << n << ": ";
    reverse(all(ans));
    for (auto v : ans) cout << (v + 1) << " ";
    cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}