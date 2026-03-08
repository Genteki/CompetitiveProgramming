// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    input(a);
    input(b);
    map<int,int> c;
    int last = 1e9;
    for (int i = 0; auto ai : a) {
        i++;
        if (ai < last) {
            last = ai;
            c[last] = i;
        }
    }
    for (auto bi : b) {
        auto it = c.upper_bound(bi);
        if (it == c.begin()) cout << -1 << endl;
        else cout << (prev(it)->second) << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}