// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
const i64 mod = 998244353 ;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> g(n);
    auto f = [&](int x) -> bool {
        for (int i = 0; i < n/2; ++i) {
            if (s[x + i] != '?' && s[x + (k - 1 - i)] != '?' &&
                s[x + i] != s[x + (k - 1 - i)]) {
                    return false;
                }
        }
        return true;
    };
    vector<bool> fix_a(n, false), fix_b(n, false);
    for (int i = 0; i < n - k + 1; ++i) {
        if (f(i)) {
            for (int j = 0; j < k; ++j) {
                if (s[i + j] == '?' && s[i + k - 1 - j] == '?') {
                    g[i + j].push_back(i + k - 1 - j);
                } else if (s[i + j] == '?' && s[i + k - 1 - j] == 'A') {
                    fix_b[i+j] = true;
                } else if (s[i + j] == '?' && s[i + k - 1 - j] == 'B') {
                    fix_a[i + j] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (fix_a[i] && fix_b[i]) {
            cout << "0" << endl;
            return;
        }
    }
    vector<bool> used(n, false);
    bool good = true;
    auto dfs = [&](auto && self, int node) -> void{
        used[node] = true;
        if (fix_a[node] || fix_b[node])  good = false;
        for (int subi : g[node]) {
            if (!used[subi]);
            self(self, subi);
        }
    };
    int cc = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i]=='?' && !fix_a[i] && !fix_b[i]) {
            good = true;
            dfs(dfs, i);
            if (good) {
                cc++;
            }
        }
    }
    i64 ans = 1;
    for (int i = 0; i < cc; ++i) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
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