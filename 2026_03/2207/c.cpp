// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, h;
    cin >> n >> h;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;

    vector<i64> left(n, 0), right(n, 0);;
    for (int i = 0; i < n; ++i) {
        if (a[i] == h) continue;
        i64 l_sum = 0;
        i64 mx_left = a[i];
        for (int j = i; j >=0; --j) {
            mx_left = max(mx_left, a[j]);
            l_sum += (h-mx_left);
        }

        i64 s = l_sum;
        left[i] = max(left[i], s);
        i64 mx_right = a[i];
        for (int j = i+1; j < n; ++j) {
            mx_right = max(mx_right, a[j]);
            s += (h-mx_right);
            left[j] = max(left[j], s);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == h) continue;
        i64 rs = 0;
        i64 mx_right = a[i];
        for (int j = i; j < n; ++j) {
            mx_right = max(mx_right, a[j]);
            rs += (h-mx_right);
        }
        i64 s = rs;
        right[i] = max(right[i] , s);
        i64 mx_left = a[i];
        for (int j = i-1; j >=0; --j) {
            mx_left = max(mx_left, a[j]);
            s += (h-mx_left);
            right[j] = max(right[j], s);
        }
    }
    i64 ans = max(right[0], left.back());
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, left[i] + right[i+1]);
    }
    cout << ans << endl;
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