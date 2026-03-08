// c2.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef long long i64;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        --b[i];
    }
    debug(a);
    vector<set<int>> occur(n);
    for (int i = 0; i < m; ++i) {
        occur[b[i]].insert(i);
    }
    vector<int> ia(n);
    for (int i = 0; i < n; ++i) {
        ia[a[i]] = i;
    }
    map<int, int> first_occur;
    for (int i = 0; i < n; ++i) {
        if (!occur[i].empty()) {
            auto it = occur[i].begin();
            first_occur[*it] = i;
        }
    }

    auto check = [&](int i) -> bool {
        if (occur[i].empty()) return true;
        if (ia[i] == 0) {
            if (first_occur.begin() -> second == i) {
                return true;
            } else {
                return false;
            }
        } else if (ia[i] == n - 1) {
            if (first_occur.rbegin() -> second == i) {
                return true;
            } else {
                return false;
            }
        } else {
            int loc = *occur[i].begin();
            auto it = first_occur.find(loc);
            if (it == first_occur.begin() || next(it) == first_occur.end()) {
                return false;
            } else if (next(it)->second == a[ia[i]+1] && prev(it)->second == a[ia[i]-1]) {
                return true;
            } else
                return false;
        }
        return false;
    };

    vector<bool> good(n, false);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        good[i] = check(i);
        if (good[i]) s++;
    }
    // for (auto [i, fi] : first_occur) cout << "(" << i << "," << fi << ") ";

    if (s == n) cout << "YA\n";
    else cout << "TIDAK\n";
    debug(good);
    auto update = [&](int i) -> void{
        if (i < 0 || i >= n) return;
        s -= good[i];
        good[i] = check(i);
        s += good[i];
    };
    for (;q--;) {
        int u,v;
        cin >> u >> v;
        --u;
        --v;
        int o = b[u];
        auto it = first_occur.find(u);
        int orr = (it == first_occur.end() ? -1 : next(it)->second);
        int ol = (it == first_occur.begin() ? -1 : prev(it)->second);
        occur[b[u]].erase(u);
        if (first_occur.find(u) != first_occur.end()) {
            first_occur.erase(u);
            if (!occur[b[u]].empty()) first_occur[*occur[b[u]].begin()] = b[u];
        }
        if (occur[v].empty()) {
            first_occur[u] = v;
        } else if (*occur[v].begin() > u) {
            first_occur[u] = v;
            first_occur.erase(*occur[v].begin());
        }
            occur[v].insert(u);
        debug(vector<pair<int,int>>(all(first_occur)));
        it = first_occur.find(v);
        int vr = (it == first_occur.end() ? -1 : next(it)->second);
        int vl = (it == first_occur.begin() ? -1 : prev(it)->second);
        update(v);
        update(vl);
        update(vr);
        update(o);
        update(ol);
        update(orr);
        debug(good);
        if (s == n)
            cout << "YA\n";
        else
            cout << "TIDAK\n";
        b[u] = v;
    }
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}