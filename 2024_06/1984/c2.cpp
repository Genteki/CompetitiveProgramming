#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int mod = 998244353;  // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);

    i64 c = 0;
    vector<i64> b;
    i64 tmp = a[0];
    i64 last = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }

        if ((a[i] > 0 && last > 0) || (a[i] < 0 && last < 0)) {
            tmp += a[i];
            last = a[i];
        } else {
            b.push_back(tmp);
            tmp = a[i];
            last = a[i];
        }
    }
    b.push_back(tmp);
    i64 ans1 = 0;
    i64 way_ans1 = 1;
    i64 way_c = 1;
    for (auto& bi : b) {
        i64 newc, newans1;
        newans1 = ans1 + bi;
        newc = max(abs(newans1), abs(c + bi));
        c = newc;
        ans1 = newans1;

        if(newc >= 0) {
            way_c = (way_c << 1) % mod;
        }

        
    }
    cout << max(c, abs(ans1)) << endl;

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