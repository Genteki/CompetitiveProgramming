#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

struct dsu {
    vector<int> root, s;
    int find_root(int node) {return root[node]==node ? node : (root[node]=find_root(root[node])); }
    void make_union(int node) {root[node] = node; s[node] = 1;}
    void unite(int a, int b) {
        a = find_root(a); b = find_root(b);
        if (a == b) return;
        if (s[a] < s[b]) swap(a, b);
        root[b] = a;
        s[a] += s[b];
    }
    dsu(int n) {root.assign(n, 0); s.assign(n, 0);}
    dsu(const dsu &other) {root = other.root; s = other.s; }
};

void solve() {
    // flush;
    int n, m, q;
    cin >> n >> m >> q;
    // cout << n;
    vector<dsu> dsu_list(m+1, dsu(n));
    for (int i = 0; i < n; ++i) {
        dsu_list[0].make_union(i);
    }
    for (int i = 1; i <= m; ++i) {
        dsu_list[i] = dsu_list[i-1];
        int x, y;
        cin >> x >> y;
        --x; --y;
        // cout << m;
        dsu_list[i].unite(x, y);
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int low = 0, high = m;
        if (dsu_list[m].find_root(x) != dsu_list[m].find_root(y)) {
            cout << -1 << endl;
            continue;
        }
        while(high-1 > low) {
            int mid = (high + low) / 2;
            if (dsu_list[mid].find_root(x) != dsu_list[mid].find_root(y)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << high << endl;
    }
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