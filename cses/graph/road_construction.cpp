// Road Construction
// https://cses.fi/problemset/task/1676
// DSU
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

struct DSU {
    vector<int> root, size;
    DSU(int n) {root.assign(n, 0); size.assign(n, 0);}
    int find_root(int v) {return v == root[v] ? v : (root[v]=find_root(root[v]));}
    void make_set(int v) {root[v] = v; size[v] = 1; }
    void unite(int a, int b) {
        a = find_root(a); b = find_root(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a, b);
        root[b] = a;
        size[a] += size[b];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    set<int> s;

    for (int i = 0; i < n; ++i) {
        dsu.make_set(i);
        s.insert(i);
    }
    int max_size = 1;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int a = dsu.find_root(x);
        int b = dsu.find_root(y);
        if (a != b) {
            if (dsu.size[a] < dsu.size[b]) {
                swap(a, b);
            }
            s.erase(b);
            dsu.root[b] = a;
            dsu.size[a] += dsu.size[b];
            max_size = max(max_size, dsu.size[a]);
        }
        cout << s.size() << " " << max_size << endl;
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
