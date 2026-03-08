// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int base = 0;
    for (int i = 0; i < n-2; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            ++base;
        }
    }
    for (;q--;) {
        int j; char c;
        cin >> j >> c;
        --j;
        char tmp = s[j];
        int start = max(0, j - 2), end = min(n, j + 3);
        int minus = 0, plus = 0;
        for (int i = start; i < end - 2; ++i) {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
                ++minus;
            }
        }
        s[j] = c;
        for (int i = start; i < end - 2; ++i) {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
                ++plus;
            }
        }
        base = (base - minus + plus);
        cout << base << endl;
    }
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