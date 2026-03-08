// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    string s;
    cin >> s;
    stack<char> st;
     for (char si : s) {
        if (!st.empty()) {
            debug(string(1, si));
            debug(string(1, st.top()));
            if (si == ']' and st.top() == '[') st.pop();
            else if (si == ')' and st.top() == '(') st.pop();
            else if (si == '>' and st.top() == '<') st.pop();
            else {st.push(si);}
        } else st.push(si);
    }
    if (st.empty()) cout << "Yes";
    else cout << "No";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}