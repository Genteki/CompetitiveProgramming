// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n,d ;
    string s;
    cin >> n >> d >> s;
    int pt = n - 1;
    while (d--) {
        while(s[pt] == '.') pt--;
        s[pt] = '.';
    }
    cout << s;
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