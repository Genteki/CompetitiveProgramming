// f.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
const i64 N = 2e5;
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<i64> a(n), b(m);
    input(a);
    input(b);
    i64 sa = accumulate(all(a), 0LL);
    i64 sb = accumulate(all(b), 0LL);
    i64 s = sa * sb;
    for (auto & ai : a) {
        ai = sa - ai;
    }
    for (auto& bi :b) bi = sb - bi;
    sort(all(a));
    sort(all(b));
    a.erase(unique(all(a)), a.end());
    b.erase(unique(all(b)), b.end());
    vector<int> exist(2 * N + 5, 0);

    for (auto bi : b) {
        if (bi == 0) exist[N] = 1;
    }
    for (auto bi : a) {
        if (bi == 0) exist[N] = 1;
    }

    for (auto ai : a) {
        if (ai > N || ai < -N) continue;
        if (ai == 0) {;continue;}
        i64 l;
        if (ai < 0) {
             l = - N / (-ai);
        } else {
             l = - N / ai;
        }
        for (auto it = lower_bound(all(b), l); it != b.end(); ++it) {
            i64 val = *it;
            if (val * ai < -N || val * ai > N) {
                break;
            }
            exist[val * ai + N] = 1;
        }
    }
    while(q--) {
        i64 x;
        cin >> x;
        if (exist[x + N]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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