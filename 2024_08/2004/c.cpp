#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n);
    input(a);

    i64 ans = 0;
    sort(all(a), greater<i64>());  // Sort in descending order

    for (int i = 0; i < n - 1; i += 2) {
        ans += (a[i] - a[i + 1]);

        // Handle the condition with 'k'
        if (k > 0) {
            if (k >= ans) {
                k -= ans;
                ans = 0;  // Reset ans if we used up all of the k
            } else {
                ans -= k;
                k = 0;
            }
        }
    }

    // If there's an odd number of elements, add the last element to the answer
    if (n % 2 == 1) {
        ans += a.back();
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        solve();
    }

    return 0;
}