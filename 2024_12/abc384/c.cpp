// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    vector<pair<int,int>> v;
    vector<int> a(5);
    input(a);
    int p = 32;
    while(p--) {
        int s = 0;
        for (int i = 0; i < 5; ++i) {
            s += a[4 - i] * bool(p & (1 << i));
        }
        v.emplace_back(p, s);
    } 
    sort(v.begin(), v.end(), [](auto& x, auto & y) -> bool {
        if (x.second != y.second) {
            return x.second > y.second;
        } else {
            return x.first > y.first;
        }
    } );
    for(auto [u, _] : v) {
        for (int i = 0; i < 5; ++i) {
            if ((1 << (4 - i)) & u) {
                cout << string(1, 'A' + i);
            }
        }
        cout << endl;
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