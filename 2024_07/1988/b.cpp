#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = true;
    for (char & si : s) {
        if (si == '0') {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes\n";
        return; 
    }
    int ans =  0;
    int x = 0;
    int b[2] = {0,0};
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            b[s[i]-'0'] += 1;
        } else if (s[i] == '0' && s[i] != s[i-1]) {
            b[0] += 1;
        } else if (s[i] == '1') {
            b[1] += 1;
        }
    }

    if (b[1] > b[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}