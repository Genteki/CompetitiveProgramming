// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int q;
    cin >> q;
    vector<i64> p;
    i64 offset = 0, tail = 0;
    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            i64 l;
            cin >> l;
            p.push_back(tail);
            tail += l;
        } else if (t == 2) {
            offset++;
        } else {
            i64 i;
            cin >> i;
            cout << p[i + offset - 1] - p[offset] << endl;
        }
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}