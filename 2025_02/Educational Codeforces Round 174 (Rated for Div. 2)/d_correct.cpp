// d_correct.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[n - 1 - i]) {
            p[i] = 1;
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = s[i] - 'a';
    vector ps(n+1, array<int,26>({0}));
    for (int i = 0; i < n; ++i) {
        ps[i+1] = ps[i];
        ps[i+1][s[i]-'a']++;
    }
    int st = -1;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) {
            st = i;
            break;
        }
    } 
    if (st == -1) {
        cout << 0 << endl;
        return;
    }
    bool f = true;
    for (int i = 0; i < 26; ++i) {
        if (ps[n/2][i] * 2 != ps[n][i]) {
            f = false;
            break;
        }
    }
    if (f) {
        for (int i = n/2-1; i>= st; --i) {
            if (p[i] == 0) {
                cout << (i-st+1) << endl;
                return;
            }
        }
    }
    int low = n/2;
    int high = n;
    while(high-low>1) {
        int mid = (low + high) / 2;
        bool g = true;
        for (int i = 0; i < 26; ++i) {
            if (ps[mid][i] * 2 < ps[n][i]) {
                g = false;
            }
        }
        if (!g) {low=mid;}
        else high = mid;
    }
    int ans = high - st;
    low = 0, high = n;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        bool g = true;
        for (int i = 0; i < 26; ++i) {
            if (ps[mid][i]*2>ps[n][i]) {
                g = false;
            }
        }
        if (!g) {high = mid;}
        else low = mid;
        
    }
    ans = min(ans, n - st - low);
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