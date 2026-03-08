// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n), a;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        b[i] = (c == 'O');
        if (b[i]) ++cnt;
        else a.push_back(i);
    }
    if ((cnt%2) != (n%2)) {
        cout << "NO" << endl;
        return;
    }
    int d = (n - cnt) / 2;
    vector<array<int,2>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i][0] = i*2+1;
        ans[i][1] = i*2+2;
    }
    for (int i = 0; i < a.size()/2; ++i) {
        int from = a[i*2], to = a[i*2+1];
        for (int p = from; p<to; ++p) {
            swap(ans[p][1], ans[p+1][0]);
        }
    }
    cout << "YES\n";
    for (auto[x,y]:ans) cout << x << " " << y << "\n";
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