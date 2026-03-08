// d.cpp kmp+manacher
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
vector<int> manacher(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        // debug(string(1,s[i]), string(1,s[n-1-i]));
        if (s[i] == s[n-1-i]) {
            p[i] = 1;
        }
    }
    int j = -1;
    debug(n,p);
    for (int i = 0; i < n; ++i) if (!p[i]) {j=i; break;}
    if (j==-1) {cout << 0 << endl;return;}
    string t =  s.substr(j, n-j*2);
    debug(t);
    // kmp
    int ans = 1e9;
    vector<int> pi(t.size());
    n = t.size();
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 and t[i] != t[j]) {
            j = pi[j - 1];
        }
        if (t[i] == t[j]) {
            ++j;
        }
        pi[i] = j;
    }
    debug(pi);
    // manacher
    reverse(t.begin(), t.end());
    string tt(n*2, ' ');
    for (int i = 0; i < n; ++i) {
        tt[2*i] = t[i];
        tt[2*i+1] = '*';
    }
    auto q = manacher(tt);
    debug(tt);
    debug(q);
    if (pi[n-1] == n/2) {cout << n/2 << endl;return;}
    for (int i = n/2-1; i>=0;--i){
        if (i%2==1 and pi[i] == (i+1)/2) {
            int delta = n/2 - pi[i];
            debug(pi[i], delta, q[delta*2-1]);
            if(q[delta*2-1]/2==delta) {
                chmin(ans, n-i);
            }
        }
    }

    if (pi[n-1] > 0) {
        debug(pi[n-1], q[n-1]);
        int delta = n/2-pi[n-1];
        if (q[n-1]/2==delta) {
            chmin(ans, pi[n-1]);
        }
    }
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 and t[i] != t[j]) {
            j = pi[j - 1];
        }
        if (t[i] == t[j]) {
            ++j;
        }
        pi[i] = j;
    }
    debug(t);
    debug(pi);
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; ++i) {
        tt[2 * i] = t[i];
        tt[2 * i + 1] = '*';
    }
    q = manacher(tt);
    debug(tt);
    debug(q);
    if (pi[n - 1] >= n / 2) {
        chmin(ans, n/2);
    }   
    for (int i = n / 2 - 1; i >= 0; --i) {
        if (i % 2 == 1 and pi[i] == (i + 1) / 2) {
            int delta = n / 2 - pi[i];
            debug(pi[i], delta, q[delta * 2 - 1]);
            if (q[delta * 2 - 1]/2 == delta) {
                chmin(ans, n-i);
            }
        }
    }
    cout << ans << endl;
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