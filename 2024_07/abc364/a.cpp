#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    int last = -1, cur = -1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        last = cur;

        if (s == "sweet") {
            cur = 1;
        } else {
            cur = 0;
        }

        if (last == 1 && cur == 1) {
            if(i != n-1) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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