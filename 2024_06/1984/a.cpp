#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n ;
    cin >> n;
    vector<int> a(n);
    input(a);

    int bl, br, rl, rr;
    bool all_same = true;
    for (auto ai : a) {
        if (ai != a[0]) {
            all_same = false;
            break;
        }
    }
    if(all_same) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            if (i == 1) {
                cout << "B";
            } else {
                cout << "R";
            }
        } 
        cout << endl;
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