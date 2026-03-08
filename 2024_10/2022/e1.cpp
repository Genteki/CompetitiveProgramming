#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct DSU {
    vector<int> parent, rank, parity;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        parity.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    // Find with path compression and parity
    int find(int x) {
        if (parent[x] != x) {
            int orig_parent = parent[x];
            parent[x] = find(parent[x]);
            parity[x] ^= parity[orig_parent];
        }
        return parent[x];
    }
    // Union by rank with parity
    bool unite(int x, int y, int w) {
        int fx = find(x);
        int fy = find(y);
        int px = parity[x];
        int py = parity[y];
        if (fx == fy) {
            if ((px ^ py) != w)
                return false;  // Inconsistency detected
            else
                return true;
        }
        if (rank[fx] < rank[fy]) {
            parent[fx] = fy;
            parity[fx] = px ^ py ^ w;
        } else {
            parent[fy] = fx;
            parity[fy] = px ^ py ^ w;
            if (rank[fx] == rank[fy]) rank[fx]++;
        }
        return true;
    }
};

int modpow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2) result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<tuple<int, int, uint32_t>> fixed_cells(k);
        for (int i = 0; i < k; i++) {
            int r, c;
            uint32_t v;
            cin >> r >> c >> v;
            fixed_cells[i] = {r - 1, c - 1, v};
        }
        uint64_t total_ans = 1;
        for (int b = 0; b < 30; b++) {
            DSU dsu(n + m);
            bool inconsistent = false;
            vector<bool> used_vars(n + m, false);
            for (auto& cell : fixed_cells) {
                int r, c;
                uint32_t v;
                tie(r, c, v) = cell;
                int bit = (v >> b) & 1;
                int ri = r;
                int ci = n + c;
                used_vars[ri] = true;
                used_vars[ci] = true;
                if (!dsu.unite(ri, ci, bit)) {
                    inconsistent = true;
                    break;
                }
            }
            if (inconsistent) {
                total_ans = 0;
                break;
            }
            // Count connected components
            vector<int> root(n + m, -1);
            int num_components = 0;
            for (int i = 0; i < n + m; i++) {
                if (used_vars[i]) {
                    int fi = dsu.find(i);
                    if (root[fi] == -1) {
                        root[fi] = 1;
                        num_components++;
                    }
                }
            }
            int num_used_vars =
                accumulate(used_vars.begin(), used_vars.end(), 0);
            int num_unused_vars = (n + m) - num_used_vars;
            int degrees_of_freedom = num_components + num_unused_vars;
            uint64_t ans_b = modpow(2, degrees_of_freedom, MOD);
            total_ans = (total_ans * ans_b) % MOD;
        }
        cout << total_ans << '\n';
    }
    return 0;
}