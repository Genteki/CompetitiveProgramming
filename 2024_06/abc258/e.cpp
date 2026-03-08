// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, q;
    i64 x;
    cin >> n >> q >> x;
    vector<i64> w(n);
    input(w);
    vector<i64> prefix_w(n+1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_w[i+1] = prefix_w[i] + w[i];
    }
    i64 rx = x % prefix_w[n];
    vector<int> nxt(n);
    vector<i64> leng(n, x/prefix_w[n]*n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while(((prefix_w[j]-prefix_w[i]+prefix_w[n]) % prefix_w[n]) < rx) {
            j = (j + 1 + n) % n;
            if (j == i) {
                leng[i] += n;
                break;
            }
        }
        nxt[i] = j;
        leng[i] += ((j+n-i)%n);
    } 
    i64 d = (x / prefix_w[n]) * n;
    // find circle;
    vector<bool> used(n, false);
    int loop_start, loop_end;
    auto dfs = [&](auto&& self, int node) -> void {
        used[node] = true;
        int to = nxt[node];
        if (used[to]) {
            loop_start = to;
            loop_end = node;
        } else {
            self(self, to);
        }
    };
    dfs(dfs, 0);
    // cout << loop_start << " " << loop_end << endl;
    // for (int nxti : nxt) cout << nxti << " "; cout << endl;
    // for (int lengi : leng) cout << lengi << " "; cout << endl;
    // before circle start
    vector<i64> before;
    int tmp = 0;

    while(tmp != loop_start) {
        before.push_back(leng[tmp]);
        tmp = nxt[tmp];
    }
    // in the loop
    vector<i64> inloop;
    tmp = loop_start;
    inloop.push_back(leng[tmp]);
    tmp = nxt[tmp];
    while(tmp != loop_start) {
        inloop.push_back(leng[tmp]);
        tmp = nxt[tmp];
    }

    i64 s1 = before.size();
    i64 s2 = inloop.size();
    // cout << s1 << " " << s2 << endl;
    // for (auto & ii : inloop) cout << ii << " "; cout << endl;
    for (;q--;) {
        i64 k;
        cin >> k;
        --k;
        if (k < s1) {
            cout << before[k] << endl;
        } else {
            k -= s1;
            k %= s2;
            cout << inloop[k] << endl;
        }
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}