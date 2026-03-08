// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    const i64 inf = 1e10;
    i64 n, q;
    cin >> n >> q;
    vector<i64> a(n);
    input(a);
    // a.push_back(inf);
    // a.push_back(-inf);
    sort(all(a));

    auto d = [&](i64 i, i64 x) -> i64 {
        return abs(a[i] - x);
    };

    auto bs = [&](i64 b, i64 k) -> i64 {
        if (d(n-1, b) < d(n-k-1, b)) return n-k;
        i64 low = 0, high = n - k;
        while(high - low > 1) {
            i64 mid = (low + high) / 2;
            if (d(mid + k - 1, b) > d(mid - 1, b)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    };

    for (; q--; ) {
        i64 b, k;
        cin >> b >> k;
        i64 l = bs(b, k);
        l = min(n-k, l);
        i64 ans = max(d(l, b), d(l+k-1, b));
        cout << ans << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}