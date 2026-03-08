// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    int sa = count(s.begin(), s.end(), 'A');
    int sb = count(s.begin(), s.end(), 'B');
    if (sa > (a + ab + ba) or sb > (b + ab +ba)) {
        cout << "NO" << endl;
        return;
    }
    
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