// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<bool> exists(n * 2 + 1, 0);
    vector<int> cnt(n * 2 + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] == r[i]) {
            exists[l[i]] = 1;
            cnt[l[i]]+=1;
        }
    }
    vector<int> ps(n*2+2,0);
    for (int i = 0; i < n*2+1; ++i) {
        ps[i+1] = ps[i] + exists[i];
    }
    for (int i = 0; i < n;++i) {
        if (l[i] == r[i]) {
            if (cnt[l[i]] >= 2) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            if (ps[r[i]+1] - ps[l[i]] == r[i]+1-l[i]) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
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