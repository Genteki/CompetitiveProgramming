// https://cses.fi/problemset/task/1688
// LCA

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<int> used;
    int n;

    void dfs(vector<vector<int>>& adj, int node, int h = 0);
    void build(int node, int b, int e);
    int query(int node, int b, int e, int L, int R);
    int query(int L, int R);

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n*2);
        used.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m*4);
        build(1, 0, m-1);

    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> boss(n, -1);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        adj[i].push_back(x);
        adj[x].push_back(i);
        boss[i] = x - 1;
    }
    LCA lca(adj);
    // for (auto i : lca.first) cout << i << " "; cout << endl;

    for (; q--;) {
        int x, y;
        cin >> x >> y;
        // cout << x << y;
        --x;
        --y;
        cout << lca.query(x, y)+1 << endl;
    }
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

void LCA::dfs(vector<vector<int>>& adj, int node, int h) {
    used[node] = true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
    for (auto & to : adj[node]) {
        if (!used[to]) {
            dfs(adj, to, h+1);
            euler.push_back(node);
        }
    }
}

void LCA::build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}

int LCA::query(int node, int b, int e, int L, int R){
    if (L > R) return -1;
    if (b == L && R == e) return segtree[node];
    int mid = (b+e) /2;
    int p = query(node << 1, b, mid, L, min(R, mid));
    int q = query(node << 1 | 1, mid+1, e, max(mid+1, L), R);
    if (p == -1) return q;
    if (q == -1) return p;
    return (height[p] > height[q]) ? q : p;
}

int LCA::query(int u, int v) {
    int L = first[u], R = first[v];
    if (L > R) swap(L, R);
    return query(1, 0, euler.size()-1, L, R);
}