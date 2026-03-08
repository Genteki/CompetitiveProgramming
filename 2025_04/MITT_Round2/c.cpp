// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string v = "rgby";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'r': a[i] = 0;
            break;
            case 'g': a[i] = 1;
            break;
            case 'b': a[i] = 2;
            break;
            case 'y': a[i] = 3;
            break;
            default:
            break;
        }
    }
    vector<int> cnt(4,0);
    for (auto ai : a ) cnt[ai]++;
    for (int i = 0 ; i < 4; ++i) {
        if (cnt[i] == 0) {
            cout << string(n, v[i]) << endl;
            return;
        }
    }
    vector<vector<int>> trans(4,vector<int>(4,0));
    for (int i = 0; i < n; ++i) {
        for (int j = max(0, i - 2); j <= min(n - 1, i + 2); ++j) {
            trans[a[i]][a[j]] = 1;
        }
    }

    pair<int, int> ilpr = {-1, -1};
    bool flag = false;
    for (int x = 0; x < 4 && !flag; x++) {
        for (int y = 0; y < 4; y++) {
            if (x != y && !trans[x][y]) {
                ilpr = {x, y};
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        string res;
        for (int i = 0; i < n; i++) {
            res.push_back(i % 2 == 0 ? v[ilpr.first] : v[ilpr.second]);
        }
        cout << res << "\n";
        return;
    }

    vector<int> x(4, 0);
    for (int i = 0; i < 3; ++i) {
        x[a[i]] = 1;
    }
    int t = -1;
    for (int i = 0; i < 4; ++i) {
        if (x[i] == 0) {
            t = i;
        }
    }
    string ans;
    reverse(s.begin(), s.end());
    cout << s.substr(1, n - 1) << v[t] << endl;
    ;
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