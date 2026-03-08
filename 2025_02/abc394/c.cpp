// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n-2; i >= 0; --i) {
        if (s[i] == 'W' and s[i+1] == 'A') {
            s[i] = 'A'; s[i+1] = 'C';
        }
    }
    cout << s;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}