// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    input(a);

    int ans = n;

    // for (int mask = 1; mask < (1 << n); ++mask) {
    //     bitset<10> flavors;

    //     // Check which stands are included in the current combination
    //     for (int i = 0; i < n; ++i) {
    //         if (mask & (1 << i)) {
    //             // If the ith stand is included, mark its flavors as covered
    //             for (int j = 0; j < m; ++j) {
    //                 if (a[i][j] == 'o') {
    //                     flavors.set(j);
    //                 }
    //             }
    //         }
    //     }

    //     if (flavors.count() == m) {
    //         ans = min(ans, __builtin_popcount(mask));
    //     }
    // }

    vector<int> flavors(n, 0);
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'o') {
                flavors[i] += (1 << j);
            }
        }
    }

    int allf = 0;
    for (int i = 0; i < m; ++i) {
        allf += (1 << i);
    }

    for (int i = 0; i <= (1 << n); ++i) {
        int this_f = 0;
        for (int j = 0; j < n; ++j) {
            // cout << (i & (1 << j));
            if (i & (1 << j)) {
                this_f |= flavors[j];
            }
        }
        // cout << i << ": " << this_f << endl;
        if (this_f == allf) {
            // cout << i << endl;
            int this_ans = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    this_ans++;
                }
            }
            ans = min(this_ans, ans);
        }
    }

    cout << ans << endl;
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