// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    i64 sl = 0, sr = 0;
    vector<i64> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        sl +=l[i] ;
        sr += r[i];
    }
    if (sl > 0 || sr < 0) {
        cout << "No";
        return;
    }
    int k = 0;
    while (sr > 0) {
        if (r[k] - l[k] >= sr) {
            r[k] -= sr;
            sr = 0;
        } else {
            sr -= (r[k] - l[k]);
            r[k] = l[k];
        }
        ++k;
    }
    cout << "Yes\n";
    for (auto ri : r) {
        cout << ri << " ";
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