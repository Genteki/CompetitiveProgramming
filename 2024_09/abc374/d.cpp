// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

double d(int x1, int y1, int x2, int y2, int v) {
    double x = (x2-x1) * (x2-x1) + (y2-y1) * (y2 -y1);
    return sqrt(x) / double(v);
}

double length(vector<int>& p, const vector<vector<int>>& a, int n, int s, int t) {
    double ans = 1e10;
    for (int i = 0; i < (1 << n); ++i) {
        int x = 0, y = 0;
        double di = 0;
        for (int j : p) {
 
            bool k = i & (1 << j);

            if (k) {
                di += d(x, y, a[j][0], a[j][1], s);
                di += d(a[j][0], a[j][1], a[j][2], a[j][3], t);
                x = a[j][2]; y = a[j][3];
            } else {
                di += d(x, y, a[j][2], a[j][3], s);
                di += d(a[j][0], a[j][1], a[j][2], a[j][3], t);
                x = a[j][0];
                y = a[j][1];
            }
        }
        ans = min(ans,di);
    }
    return ans;
}

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>> a(n, vector<int>(4));
    for (auto & ai : a) input(ai);
    vector<int> permuation(n);
    for (int i = 0; i < n; ++i) {
        permuation[i] = i;
    }
    double ans = 1e10;
    do {    
        ans = min(ans, length(permuation, a, n, s, t));
    } while(next_permutation(all(permuation)));
    cout << setprecision(20) << ans << endl;
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