#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n), b(n);
    input(a);
    input(b);

    i64 s = accumulate(all(b), 0LL);  // Sum of all elements in b

    multimap<i64, i64> ma;  // Multimap for a[i] -> b[i]
    multimap<i64, i64> mb;  // Multimap for b[i] -> a[i]

    for (int i = 0; i < n; ++i) {
        ma.insert({a[i], b[i]});
        mb.insert({b[i], a[i]});
    }

    for (int z = 0; z < n - k; ++z) {
        auto it_ma = prev(ma.end());  // Iterator for max a[i]
        auto it_mb = prev(mb.end());  // Iterator for max b[i]

        i64 a1 = it_ma->first, b1 = it_ma->second;
        i64 b2 = it_mb->first, a2 = it_mb->second;

        if (a1 == a2 && b1 == b2) {
            // If both maximum elements are the same, remove them
            s -= b1;
            ma.erase(it_ma);
            mb.erase(it_mb);
            continue;
        }

        auto it_next_ma = prev(it_ma);  // Next largest element in ma
        i64 x1 = (it_next_ma->first) * (s - b1);
        i64 x2 = a1 * (s - b2);

        if (x1 < x2) {
            s -= b1;
            ma.erase(it_ma);
            auto range = mb.equal_range(b1);  // Remove specific b1 from mb
            for (auto it = range.first; it != range.second; ++it) {
                if (it->second == a1) {
                    mb.erase(it);
                    break;
                }
            }
        } else {
            s -= b2;
            mb.erase(it_mb);
            auto range = ma.equal_range(a2);  // Remove specific a2 from ma
            for (auto it = range.first; it != range.second; ++it) {
                if (it->second == b2) {
                    ma.erase(it);
                    break;
                }
            }
        }
    }

    i64 ans = s * ma.rbegin()->first;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}