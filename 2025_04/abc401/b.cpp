// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string login = "login";
    string logout = "logout";
    string pub = "public";
    string pri = "private";
    int n;
    cin >> n;
    bool status = 0;
    int cnt = 0;
    while(n--) {
        string s;
        cin >> s;
        if (s==login) {
            status = 1;
        } else if (s==logout) {
            status = 0;
        } else if (s==pri) {
            if (status == 0) ++cnt;
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