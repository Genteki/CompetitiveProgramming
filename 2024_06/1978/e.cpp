// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    char tmp;
    for (int & ai : a) {
        cin >> tmp;
        if (tmp == '1') ai = 1;
        else ai = 0;
    }  
    for (int & ai : b) {
        cin >> tmp;
        if (tmp == '1') ai = 1;
        else ai = 0;
    }  
    auto old_a = a;
    auto old_b = b;
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto & qi : queries) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        qi = {l, r};
    }

    for (int i = 0; i < n - 2; ++i) {
        if (a[i] == 0 && a[i+2] == 0) {
            b[i+1] = 1;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        if (b[i] == 1 && b[i+2] == 1) {
            a[i+1] = 1;
        }
    }

    vector<int> a1n(n+1, 0);
    for (int i = 1; i < n+1; ++i) {
        if (a[i-1] == 1) {
            a1n[i] = a1n[i-1] + 1;
        } else {
            a1n[i] = a1n[i-1];
        }
        // cout << " " << a1n[i];
    }
    // cout << endl;

    for (auto & qi : queries) {
        int l = qi.first, r = qi.second;
        int x = a1n[qi.second + 1] - a1n[qi.first];
        unordered_set<int> checked;
        if (old_a[r]==0 && a[r]==1) {--x; checked.insert(r);}
        if ((r-1>=l) && old_a[r-1]==0 && a[r-1]==1 && old_b[r]==0 && b[r]==1) {--x;checked.insert(r-1);}
        if (old_a[l] == 0 && a[l] == 1 && checked.find(l) == checked.end()) --x;
        if ((l+1<=r) && old_a[l+1] == 0 && a[l+1] == 1 && old_b[l]==0 && b[l]==1 && checked.find(l+1) == checked.end()) --x;

        cout << (x) << endl;
    }

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