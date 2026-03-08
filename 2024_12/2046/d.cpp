// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<i64> p, q;
    int r = 1e9+5;
    for (int i = n-1;i >= 0; --i) {
        if (a[i] <= r) {
            r = a[i];
            p.push_back(a[i]);
        } else {
            q.push_back(a[i]);
        }
    }
    reverse(all(p));
    if (q.empty()) {
        for (auto ai : p) cout << ai << " ";
        cout << endl;
        return;
    }
    i64 qm = *min_element(all(q));
    vector<i64> ans;
    for (auto pi : p) {
        if (pi <= qm + 1) {
            ans.push_back(pi);
        }else {
            q.push_back(pi);
        }
    }
    sort(all(q));
    for (auto qi : q) ans.push_back(qi+1);
    for (auto ai : ans) cout << ai << " ";
    cout << endl;

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}