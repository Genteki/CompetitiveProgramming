#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

struct LCA {
    int n, eulersize;
    vector<vector<int>> adj;
    vector<int> first;
    vector<int> segtree;
    vector<int> height;
    vector<bool> viewed;
    vector<int> euler;
    LCA(vector<vector<int>> &init_adj, int root=0) {
        adj = init_adj;
        n = adj.size();
        first.resize(n);
        height.resize(n);
        viewed.assign(n, false);
        euler.reserve(n*2);
        dfs(root, 0);
        eulersize = euler.size();
        segtree.assign(4 * eulersize, -1);
        build(1, 0, eulersize-1);
    }
    void build(int node, int l, int r) {
        if (l==r) {
            segtree[node] = euler[l];
        } else {
            int m = (l+r) /2;
            build(node*2, l, m);
            build(node*2+1, m+1, r);
            int al = segtree[node*2], ar =segtree[node*2+1];
            segtree[node] = (height[al] < height[ar]) ? al : ar;
        }
    }
    void dfs(int node, int h=0) {
        viewed[node]=true;
        first[node]=euler.size();
        // cout << node << ":" << first[node] << endl;
        euler.push_back(node);
        height[node] = h;
        for (int &to : adj[node]) {
            if (!viewed[to]) {
                dfs(to, h+1);
                euler.push_back(node);
            }
        }
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > qr) {
            return -1;
        }
        if (l == ql && r == qr) {
            return segtree[node];
        } 
        int m = (l+r) / 2;
        int al = query(node*2, l, m, ql, min(qr, m));
        int ar = query(node*2+1, m+1, r, max(m+1, ql), qr);
        if (al == -1) return ar;
        else if (ar == -1) return al;
        else {
            return (height[al] < height[ar]) ? al : ar;
        }
        
        return -1;
    }
    int query(int ql, int qr) {
        ql = first[ql];
        qr = first[qr];
        if (ql > qr) swap(ql, qr);

        return query(1, 0, eulersize-1, ql, qr);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    LCA lca(adj);
    // cout << "euler size :" << lca.eulersize << endl;
    // for (auto euleri : lca.segtree) cout << euleri << " "; cout << endl;
    // for (auto euleri : lca.euler) cout << euleri << " "; cout << endl;
    // for (auto euleri : lca.height) cout << euleri << " "; cout << endl;
    for(;q--;) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int h = lca.height[lca.query(x, y)];
        int hx = lca.height[x];
        int hy = lca.height[y];
        // cout << lca.first[x] << " " << lca.first[y] <<  " " << h;
        int d = hx + hy - h - h;
        cout << d << endl;
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