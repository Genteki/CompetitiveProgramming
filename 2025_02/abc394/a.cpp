#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (char si : s) if (si == '2') ++cnt;
    for (int i = 0; i < cnt; ++i) cout << 2;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}