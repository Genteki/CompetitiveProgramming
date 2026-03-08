// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    string s;
    map<char, int> mp;
    int n;
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << s << endl;
        return;
    }
    for (auto si : s) {
        mp[si]++;
    }
    int pt=-1;
    char mx, mi='.';
    for (auto [c, cnt] : mp) {
        if (cnt > pt) {
            pt = cnt;
            mx = c;
        }
    }
    pt = 100;
    for (auto [c, cnt] : mp) {
        if (cnt < pt && c != mx) {
            pt = cnt;
            mi = c;
        }
    }
    if (mi != '.') {
        for (auto & si : s) {
            if (si == mi) {
                si = mx;
                break;
            }
        }
    }
    cout << s << endl;
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