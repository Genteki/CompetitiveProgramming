// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void brute_force() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    cerr << k << ": ";
    if (n % 2 == 0) {
        int s = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            cerr << s;
            if (!a[s]) {
                a[s] = 1;
            } else {
                good = false;
                break;
            }
            if (i % 2 == 0) {
                if ((n + s - k) % n == n / 2)
                    s = k;
                else
                    s = (2 * k - s + n) % n;
            } else {
                s = (n - s) % n;
            }
        }
        if (good) {
            cout << "Yes" << endl;
            return;
        }
        cerr << endl;
        fill(all(a), 0);

        good = true;
        s = n / 2;
        for (int i = 0; i < n; ++i) {
            cerr << s;
            if (!a[s]) {
                a[s] = 1;
            } else {
                good = false;
                break;
            }
            if (i % 2 == 0) {
                if ((n + s - k) % n == n / 2)
                    s = k;
                else
                    s = (2 * k - s + n) % n;
            } else {
                s = (n - s) % n;
            }
        }
        if (good) {
            cout << "Yes" << endl;
            return;
        }
    } else {
        int s = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            cerr << s;
            if (!a[s]) {
                a[s] = 1;
            } else {
                good = false;
                break;
            }
            if (i % 2 == 0) {
                s = (2 * k - s + n) % n;
            } else {
                s = (n - s) % n;
            }
        }
        if (good) {
            cout << "Yes" << endl;
            return;
        }
    }
    cerr << endl;

    cout << "No" << endl;
    return;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1) {
        // For odd n
        if (__gcd(k, n) == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else {
        // For even n
        if (__gcd(k, n / 2) == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
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