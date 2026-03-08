// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) -> bool {return a[l] > a[r];});
    i64 ans = 0, s = 0;
    if (k == 1) {
        if (a[0] < a[n-1]) swap(a[0], a[n-1]);
        ans = a[0] + *max_element(a.begin()+1, a.end());
        cout << ans << endl;
        return;
    } else {
        for (int i = 0; i < k+1; ++i) {
            s += a[ord[i]];
        }
    }
    cout << s << endl;
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
