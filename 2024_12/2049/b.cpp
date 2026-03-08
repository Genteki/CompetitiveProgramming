// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n, -1), r(n, -1);
    int lp = -1, ls = -1,fp =-1, fs = -1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 's') {
            ls = i;
            if(fs ==-1) fs=i;
        }
    }
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == 'p') {
            lp = i;
            if (fp == -1) fp = i;
        }
    }
    // cout << fp << ls;
    if (lp != -1 && ls != -1) {
        cout << "NO" << endl;
        return;
    }
    cout <<"YES\n";
    return;
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