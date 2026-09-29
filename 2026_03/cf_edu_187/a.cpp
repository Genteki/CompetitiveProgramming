#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

bool chmax(int& a, int b){ return b > a ? a = b, true : false; }

void solve() {
    i64 n, m, d;
    cin >> n >> m >> d;
    i64 x = d / m;
    x = min(x+1, n);
    cout << ceil(float(n)/x) << endl;
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