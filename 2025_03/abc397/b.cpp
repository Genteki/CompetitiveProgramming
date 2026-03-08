// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    string s;
    cin >> s;
    n = s.size();
    int cnt = n;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == 'i' && s[i+1] == 'o') {
            ++i;
            cnt -= 2;
        }
    }
    cout << cnt;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}