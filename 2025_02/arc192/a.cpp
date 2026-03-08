#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n % 4 == 0) {
        cout << "Yes";
        return;
    }
    if (n % 2) {
        if (accumulate(a.begin(), a.end(), 0))
            cout << "Yes";
        else
            cout << "No";
    } else {
        vector<int> odd, even;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1){
                if (i%2 == 1) {odd.push_back(i);odd.push_back(i+n);}
                else {even.push_back(i);even.push_back(i+n);}
            }
            if (a[i]==1 and a[(i+1)%n] == 1) {
                cout << "Yes";
                return;
            }
        }
        for (int i : odd) {
            if (i < n) {
                auto it1 = lower_bound(even.begin(), even.end(), i + 3);
                auto it2 = upper_bound(even.begin(), even.end(), i + n - 3);
                if (distance(it1, it2)) {
                    cout << "Yes";
                    return;
                }
            }
        }

        cout << "No";
    }


    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}