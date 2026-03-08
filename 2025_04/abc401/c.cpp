// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 mod = 1e9;

void solve() {
    int n,k;
    cin >> n >> k;

    deque<i64> a(k, 1);
    i64 s = k;
    n = n + 1 - k;
    if (n <= 0) {
        cout << 1;
        return;
    }
    while(--n) {
        a.push_back(s);
        s += s;
        s -= a.front();
        s = (s+mod) %mod;
        a.pop_front();
    }
    cout << (s);
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

        solve();
}