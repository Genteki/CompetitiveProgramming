// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int N = 1e5+5;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
vector<int> prime(N, 1);
vector<int> prime_list;
void solve() {
    int n;
    cin >> n;
    int t = *lower_bound(prime_list.begin(), prime_list.end(), 1+(n)/2);
    vector<int> a(n,-1);
    a[0] = t;
    int idx = 1;
    for (int i = t + 1; i <= n; ++i) {
        a[idx] = i;
        a[idx+1] = t*2-i;
        idx+=2;
    }
    debug(a);
    for (int i = 0; i < n; ++i) {
        if (a[n-1-i] == -1) {
            a[n-1-i] = i+1;
        } else break;
    }
    for (auto ai : a ) cout << ai << " ";
    cout << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i*i< N; ++i) {
        if (!prime[i]) continue;
        for (int j = i*i; j < N; j+=i) {
            prime[j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (prime[i]) prime_list.push_back(i);
    }

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}