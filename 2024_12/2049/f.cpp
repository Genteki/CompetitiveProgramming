// f.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define int long long 
struct DSU {
    int n;
    std::vector<int> root, rank;
    vector<map<int, int>> vs;
    DSU(int n) : n(n) { init(n); }
    void init(int n) {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        rank.assign(n, 1);
        vs.resize(n);
    }
    int find(int x) {
        while(x != root[x]) {
            x = root[x] = root[root[x]];
        }
        return x;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) std::swap(a, b);
        root[b] = a;
        rank[a] += rank[b];

        for (auto &[i, num] : vs[b]) {
            vs[a][i] += num;
        }
        vs[b].clear();

        return true;
    }
    void update(int pos, int prev, int cur) {
        pos = find(pos);
        vs[pos][cur]++;
        if ((--vs[pos][prev]) == 0) {
            vs[pos].erase(prev);
        }
    }

    int siz(int pos) {
        pos = find(pos);
        return vs[pos].size();
    }
    int max_ele(int pos) {
        pos = find(pos);
        return (vs[pos].rbegin()->first);
    }
    bool good(int h, int i) {
        i = find(i);
        if (max_ele(i) == h && siz(i) == h+1) return true;
        return false; 
    }

    DSU(const DSU& other) {
        root = other.root;
        rank = other.rank;
    }
    int leng(int u) {
        return rank[find(u)];
    }
};
bool chmax(int& a, const int& b){ return b > a ? a = b, true : false; }
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto&ai : a) cin >> ai;
    vector<pair<int,int>> qs(q);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        qs[i] = {u, v};
    }
    vector<int> c(q, 0);
    for (int k = 0; (1 << k) <= n; ++k) {
        map<int, int> ans;

        int h = (1 << k) - 1;
        auto b = a;
        for (auto [u, v] : qs) {
            b[u] += v;
        }

        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            dsu.vs[i][b[i]]++;
            if (i > 0 && b[i] <= h && b[i-1] <= h) {
                dsu.unite(i-1,i);
            }
        }
        debug(h);
        vector<int> viewed(n, 0);
        for (int i = n-1; i >= 0; --i) {
            if (!viewed[dsu.find(i)] && dsu.good(h, i)) {
                ans[dsu.rank[i]]++;
            }
        }
        if(!ans.empty()) chmax(c[q-1], (ans.rbegin()->first));
        debug(c);

        for (int i = q-1; i > 0; --i) {
            auto [u, v] = qs[i];
            if (dsu.good(h, u)) {
                ans[dsu.leng(u)]--;
                if (ans[dsu.leng(u)] <= 0)
                    ans.erase(dsu.leng(u));
            }
            dsu.update(u, b[u], b[u] - v);
            if (b[u]-v <= h) {
                if (u>0 && dsu.max_ele(u-1) <= h) {
                    int l = dsu.rank[dsu.find(u-1)];
                    if (dsu.unite(u, u-1) and dsu.good(h, u-1) ) {
                        ans[l]--;
                        if (ans[l] <= 0)
                            ans.erase(l);
                    }
                }
                if (u < n-1 and dsu.max_ele(u+1) <= h) {
                    int l = dsu.rank[dsu.find(u + 1)];
                    if (dsu.unite(u, u+1) && dsu.good(h, u+1)){
                        ans[l]--;
                        if (ans[l] <= 0) ans.erase(l);
                    }
                }
                if (dsu.good(h, u)) {
                    debug(u, dsu.rank[dsu.find(u)]);
                    ans[dsu.rank[dsu.find(u)]]++;
                }
            }
            b[u]-=v;
            if (!ans.empty()) chmax(c[i-1], ans.rbegin()->first);
        }

        debug(k, ans);
    }
    for (auto ai : c) {
        cout << ai << endl;
    }
    debug(2);

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}