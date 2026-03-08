// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> x(n, false);
    for (;m--;) {
        int a; char b;
        cin >> a >> b;
        --a;
        if (!x[a] && b == 'M') {
            x[a] = true;
            cout << "Yes\n";
        } else cout << "No\n";
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