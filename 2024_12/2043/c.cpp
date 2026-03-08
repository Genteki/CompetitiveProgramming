#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
using pr = pair<i64,i64>;
pr subArr(const vector<int> &v) {
    i64 curr = 0, minPrefix = 0, maxPrefix = 0, mn = 0, mx = 0;
    for (auto &x : v) {
        curr += x;
        mx = max(mx, curr - minPrefix);
        mn = min(mn, curr - maxPrefix);
        minPrefix = min(minPrefix, curr);
        maxPrefix = max(maxPrefix, curr);
    }
    return {mn, mx};
}

pr preMinMax(const vector<int> &v) {
    i64 p = 0, mn = 0, mx = 0;
    for (auto &x : v) {
        p += x;
        mn = min(mn, p);
        mx = max(mx, p);
    }
    return {mn, mx};
}

pr sufMinMax(const vector<int> &v) {
    i64 p = 0, mn = 0, mx = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        p += v[i];
        mn = min(mn, p);
        mx = max(mx, p);
    }
    return {mn, mx};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int pos = -1;
    i64 special = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1 && a[i] != 1) {
            pos = i;
            special = a[i];
            break;
        }
    }
    vector<int> left, right;
    if (pos == -1) {
        left = a;
    } else {
        for (int i = 0; i < pos; i++) left.push_back(a[i]);
        for (int i = pos + 1; i < n; i++) right.push_back(a[i]);
    }

    auto L = subArr(left);
    auto R = subArr(right);

    vector<pr> intvl;
    intvl.push_back({0, 0});
    intvl.push_back({L.first, L.second});
    intvl.push_back({R.first, R.second});

    if (pos != -1) {
        auto SL = sufMinMax(left);
        auto PR = preMinMax(right);
        i64 crossMin = SL.first + special + PR.first;
        i64 crossMax = SL.second + special + PR.second;
        intvl.push_back({crossMin, crossMax});
    }

    sort(intvl.begin(), intvl.end());

    vector<pr> merged;
    for (auto &iv : intvl) {
        if (merged.empty() || iv.first > merged.back().second + 1) {
            merged.push_back(iv);
        } else {
            merged.back().second = max(merged.back().second, iv.second);
        }
    }

    vector<i64> ans;
    for (auto &iv : merged) {
        for (i64 x = iv.first; x <= iv.second; x++) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << endl;
    for (auto &x : ans) cout << x << " ";
    cout << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}