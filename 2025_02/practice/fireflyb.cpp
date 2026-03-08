// fireflyb.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 mod = 998244353;

// https://cp-algorithms.com/string/suffix-automaton.html

struct state {
    int len, link;
    map<char, int> next;
    int cnt;
};

const int MAXLEN = 1000000;
state st[MAXLEN * 2];
int sz, last;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
    st[0].cnt = 0;
    st[0].next.clear();
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].next.clear();
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            st[clone].cnt = 0;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

vector<i64> modexp2(MAXLEN+1, 1);


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sa_init();
    for (char c : s) {
        sa_extend(c);
    }
    vector<int> ord(sz);
    for (int i = 0; i < sz; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return st[a].len > st[b].len;
    });
    for (int i = 0; i < sz; i++) {
        int v = ord[i];
        if (st[v].link != -1) {
            st[st[v].link].cnt += st[v].cnt;
        }
    }
    i64 ans = 0;

    // c(k, 0) + c(k, 1) + .. + c(k, k) = (1+1)^k
    for (int v = 1; v < sz; v++) {
        int diff = st[v].len - st[st[v].link].len;
        i64 ck = (modexp2[st[v].cnt] - 1) % mod;
        if (ck < 0) ck += mod;
        ans = (ans + (i64)diff * ck) % mod;
    }

    cout << ans % mod << "\n";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < MAXLEN; ++i) {
        modexp2[i+1] = modexp2[i] * 2 % mod;
    }

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}