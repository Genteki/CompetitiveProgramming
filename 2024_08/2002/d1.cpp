#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, q;
    cin >> n >> q;
    int l = 0;
    int m = n;
    while( m > 0) {
        m = m >> 1;
        l++;
    }
    vector<int> parent(n, -1), p(n), pos(n);
    vector<vector<int>> adj(n);

    for (int i = 1; i < n; ++i) {
        cin >> parent[i];
        parent[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        pos[p[i]] = i;
    }

    for (int i = 1; i < n; ++i) {
        adj[parent[i]].push_back(i);
    }

    vector<int> source(n, -1);
    vector<pair<int,int>> sons(n, {-1,-1});
    auto dfs = [&](auto && self, int node, int d = 0) -> void {
        if (d < l - 1) {
            int s1 = node + 1;
            int s2 = node + (1 << (l - d - 1));
            source[s1] = node;
            source[s2] = node;
            sons[node] = {s1, s2};
            self(self, s1, d+1);
            self(self, s2, d+1);
        }
    };

    dfs(dfs, 0, 0);

    vector<bool> correct(n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (sons[i] == make_pair(-1,-1) && adj[p[i]].empty()) {
            correct[i] = true;
            cnt++;
        } else if (sons[i] != make_pair(-1, -1) && !adj[p[i]].empty()) {
            int j = p[i];
            if (p[sons[i].first] == adj[j][0] && p[sons[i].second] == adj[j][1]) {
                correct[i] = true;
                cnt++;
            } else if (p[sons[i].first] == adj[j][1] && p[sons[i].second] == adj[j][0]) {
                correct[i] = true;
                cnt++;
            }
        }
    }


    auto check = [&](int i, int new_val) -> void {
        // bool nxt;
        // cout << i << ":";
        if (sons[i] == make_pair(-1, -1) && adj[new_val].empty()) {
            correct[i] = true;
        } else if (sons[i] != make_pair(-1, -1) && !adj[new_val].empty()) {
            if (p[sons[i].first] == adj[new_val][0] && p[sons[i].second] == adj[new_val][1]) {
                correct[i] = true;
            } else if (p[sons[i].first] == adj[new_val][1] && p[sons[i].second] == adj[new_val][0]) {
                correct[i] = true;
            } else {
                correct[i] = false;
            }
        } else {
            correct[i] = false;
        }
        cnt = cnt + int(correct[i]);
        // cout << endl;
    };


    // for (auto ci : correct) cout << ci << " "; cout << endl;
    for(;q--;) {
        int a, b, c, d;
        cin >> a >> b;
        --a; --b;
        int pa = p[a], pb = p[b];
        c = source[a];
        d = source[b];
        // cout << a << b << c << d << endl;

        cnt = cnt - (int)correct[a] - (int)correct[b] ;
        if (c != a && c != b && c != -1) cnt -= (int)correct[c];
        if (d != a && d != b && d != c && d != -1) cnt -= (int)correct[d];
        p[a] = pb;
        p[b] = pa;
        pos[pa] = b;
        pos[pb] = a;
        // for (auto pi : p) cout << pi; cout << endl; 
        // cout << p[a] << p[b] << p[c] << p[d] << endl;
        // cout << p[c+1] << p[c+2]  << adj[c].size();
        check(a, p[a]);
        check(b, p[b]);
        // check(c, p[c]);

        if (c != a && c != b && c != -1) check(c, p[c]);
        if (d != a && d != b && d != c && d != -1) check(d, p[d]);
        if (cnt == n) cout << "YES";
        else cout << "NO";
        cout << endl;
        // check a 
        // for (auto ci : correct) cout << ci << " "; cout << endl;
        
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