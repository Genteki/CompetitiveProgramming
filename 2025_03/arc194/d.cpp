// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
const i64 MOD = 998244353;
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    i64 ans  = 0;
    auto f = [&s,&ans](auto&& self, int ql, int qr, int depth = 0) -> i64 {
        if (ql >= qr) return 0;
        int l = ql, r = l-1;
        i64 ret = 0;
        stack<char> st;
        while(l < qr) {
            debug(l);
            st.push(l);
            r = l + 1;
            i64 md = 1;
            i64 cur = 0;
            while(r<qr and !st.empty()) {
                if (s[r] == ')') {
                    st.pop();
                } else {
                    st.push('(');
                }
                ++r;
                md = max<i64>(md, st.size());
            }
            // if (l == ql and r== qr) break;
            if (md <= depth) ++cur;
            cur += self(self, l+1, r-1, depth + 1);
            cur %= MOD;
            ret = ((1 + ret) * (1+cur) - 1);
            ret %= MOD;
            debug(l, r, cur, ret);
            l = r;
        }
        return ret;
    };
    ans = f(f, 0, n);
    cout << (ans+1+MOD)%MOD;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}