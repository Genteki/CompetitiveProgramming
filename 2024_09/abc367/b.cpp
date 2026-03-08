// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> a,b ;
    int i = 0;
    while(i < n && s[i] != '.') {
        a.push_back(s[i]);
        ++i;
    }
    ++i;
    while(i < n) {
        b.push_back(s[i]);
        ++i;
    }
    while(b.back() == '0') b.pop_back();
    for (auto ai : a) cout << ai;
    if (b.size()) cout << ".";
    for (auto bi : b) cout << bi;

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}