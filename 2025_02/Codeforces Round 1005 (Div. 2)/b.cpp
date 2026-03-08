// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = cnt[a[i]];
    }
    int l=-1,r=-1,len=0;
    int i = 0;
    while (i<n) {
        int j = 0;
        while(i+j < n and b[i+j]==1) {
            ++j;
        }
        if (j > len) {
            l = i+1;
            r = i + j;
            len = j;
        }
        i+=max(1,j);
    }
    if (len == 0) {
        cout << 0 << endl;
    } else {
        cout << l << " " << r << endl;
    }
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