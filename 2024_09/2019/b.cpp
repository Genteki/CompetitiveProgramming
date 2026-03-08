// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<i64> a(n);
    input(a);
    map<i64, i64> mp;
    for (i64 i = 0; i < n - 1; ++i) {
        i64 m = a[i+1] - a[i] - 1;
        i64 p = (i + 1) * (n - 1 - i);
        mp[p] += m;
    }
    for (i64 i = 0; i < n; ++i) {
        i64 m = 1;
        i64 p = (i+1) * (n - i) - 1;
        mp[p] += m; 
    }
    for (;q--;) {
        i64 qi;
        cin >> qi;
        cout << mp[qi] << " ";
    }
    cout << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}