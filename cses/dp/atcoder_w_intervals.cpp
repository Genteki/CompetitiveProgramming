#include <bits/stdc++.h>
/*
W - Intervals
actually no.
some intervals are extra

dp[i] => max value I pick up by setting this to be 1.
dp[i] = std::max(dp[j] + cost(i,j))
cost(i,j) => sum ai for all those with i >= l > j and r >=i
when I'm at i I need to know all those who are in touch with i and those who are
after me when I hit an l I need to update the prefix with add to a range and
then ask the max activate and deactivating ranges is probably the correct word
would have to have point updates too when writing dp[i]

how should a lazy tree be?
lazy[node] stores updates and tree[node] would have that update already
when you find a range which comes under query you add the lazy there and move
on. when you want to go down further push down would never wanna push down when
you're doing.
*/
using cost = long long;
class LazySegtree {
    std::vector<cost> tree;
    std::vector<cost> lazy;
    size_t n;
    void push(int node) {
        tree[node << 1] += lazy[node];
        tree[node << 1 | 1] += lazy[node];
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        lazy[node] = 0;
    }
    cost query(int x, int ql, int qr, int tl, int tr) {
        //   std::cerr<<x<<" "<<ql<<" "<<qr<<" "<<tl<<" "<<tr<<"\n";
        if (qr < tl || tr < ql) return LLONG_MIN;
        if (ql <= tl && tr <= qr) {
            return tree[x];
        }
        push(x);
        auto tm = std::midpoint(tl, tr);
        return std::max(query(x << 1, ql, qr, tl, tm),
                        query(x << 1 | 1, ql, qr, tm + 1, tr));
    }
    void update(int x, cost val, int ql, int qr, int tl, int tr) {
        //   std::cerr<<x<<" "<<val<<" "<<ql<<" "<<qr<<" "<<tl<<" "<<tr<<"\n";
        if (qr < tl || tr < ql) return;
        if (ql <= tl && tr <= qr) {
            tree[x] += val;
            lazy[x] += val;
            return;
        }
        push(x);
        auto tm = std::midpoint(tl, tr);
        update(x << 1, val, ql, qr, tl, tm);
        update(x << 1 | 1, val, ql, qr, tm + 1, tr);
        tree[x] = std::max(tree[x << 1], tree[x << 1 | 1]);
    }

   public:
    LazySegtree(size_t n) : n(n) {
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    cost query(int l, int r) { return query(1, l, r, 0, n - 1); }
    void update(cost val, int l, int r) { update(1, val, l, r, 0, n - 1); }
    void debug() {
        std::cerr << "tree\n";
        for (auto x : tree) {
            std::cerr << x << " ";
        }
        std::cerr << "\n";

        std::cerr << "lazy tree\n";
        for (auto x : lazy) {
            std::cerr << x << " ";
        }
        std::cerr << "\n";
    }
};
int n, m;
std::vector<std::array<int, 3>> intervals;
std::vector<std::vector<std::array<int, 2>>> L, R;
std::vector<cost> dp;
int main() {
    std::cin >> n >> m;
    L.assign(n + 1, std::vector<std::array<int, 2>>(0));
    R.assign(n + 1, std::vector<std::array<int, 2>>(0));
    dp.assign(n + 1, 0);
    LazySegtree tree(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r, a;
        std::cin >> l >> r >> a;
        intervals.push_back({l, r, a});
        L[l].push_back({r, a});
        R[r].push_back({l, a});
    }
    for (int i = 1; i <= n; i++) {
        // std::cerr<<i<<"\n";
        for (auto [r, a] : L[i]) {
            tree.update(a, 0, i - 1);
        }
        // std::cerr<<"After L\n";
        // tree.debug();
        dp[i] = tree.query(0, i - 1);
        tree.update(dp[i], i, i);
        // std::cerr<<"After dp\n";
        // tree.debug();
        for (auto [l, a] : R[i]) {
            tree.update(-a, 0, l - 1);
        }
        // std::cerr<<"After R\n";
        // tree.debug();
    }
    // tree.debug();
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
    // std::cerr<<"dp\n";
    // for(auto x: dp){
    //     std::cerr<<x<<" ";
    // }
    // std::cerr<<"\n";
}