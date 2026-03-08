#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> st;
    int wu = (n + m - 1) / m;
    int wd = n / m;
    for (int w = 1; w < n ; ++w) {
        for (int c = 0; c < w; ++c) {
            bool flag = true;
            if (! ((c+(m-1)*w) < n && (c + m * w >= n))) continue;
            for (int i = 0; i < m; ++i) {
                if (t[i] != s[i * w + c]) {
                    flag = false;
                }
            }
            if (flag) {
                cout << "Yes";
                return;
            }
        }
    }
    
    cout << "No";
    
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}