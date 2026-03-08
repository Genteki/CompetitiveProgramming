// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const string F = "Fennec";
const string S = "Snuke";

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& ai : a) cin >> ai;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2)
            ++odd;
        else
            ++even;
    }

    if (n == 1) {
        cout << F;
        return;
    }
    if (n == 2) {
        cout << S;
        return;
    }
    if (n == 3) {
        if (odd) {
            cout << F;
        } else {
            cout << S;
        }
        return;
    }
    if (odd % 2 == 1) {
        cout << F;
    } else {
        cout << S;
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