#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }

    vector<vector<char>> t(m, vector<char>(n, '*'));
    for (int i = 0; i < n; ++i) {
        int ii = n - i - 1;
        for (int j = 0; j < s[i].size(); ++j) {
            t[j][ii] = s[i][j];
        }
    }

    for (auto & ti : t) {
        for (int i = ti.size()-1; i >= 0; --i) {
            if (ti[i] == '*') {
                ti.pop_back();
            } else {
                break;
            }
        }
        for (auto &tii : ti) {
            cout <<tii;
        } cout << endl;
    }

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