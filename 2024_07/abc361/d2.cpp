// d2.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    int N = (1 << n) * (n + 1);
    int l = 1 << n;
    vector<bool> viewed(N, false);
    vector<char> s(n + 2, '.');
    vector<char> t(n + 2, '.');

    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    auto encode = [&n, &l](vector<char>& x) -> int {
        int ppos = 0;
        for (int i = 0; i < n + 2; ++i) {
            if (x[i] == '.') {
                ppos = i;
                break;
            }
        }
        int j = 0;
        int r = 0;
        for (char& xi : x) {
            if (xi == 'B') {
                r += (1 << j);
                ++j;
            } else if (xi == 'W') {
                ++j;
            }
        }
        r += (l * ppos);
        return r;
    };

    queue<vector<char>> q;
    vector<int> parent(N, -1);
    q.push(s);
    int tc = encode(t), sc = encode(s);
    parent[sc] = -2;  // Mark the start state

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int pc = encode(p);
        if (pc == tc) break;
        if (viewed[pc]) continue;
        viewed[pc] = true;

        int ppos = 0;
        for (int i = 0; i < n + 2; ++i) {
            if (p[i] == '.') {
                ppos = i;
                break;
            }
        }

        for (int i = max(0, ppos - 1); i <= min(n, ppos + 1); ++i) {
            if (i != ppos && p[i] != '.' && p[ppos] != '.') {
                auto to = p;
                swap(to[i], to[ppos]);
                int toc = encode(to);
                if (!viewed[toc]) {
                    q.push(to);
                    parent[toc] = pc;
                }
            }
        }
    }

    if (!viewed[tc]) {
        cout << -1 << endl;
    } else {
        int steps = 0;
        for (int cur = tc; cur != sc; cur = parent[cur]) {
            ++steps;
        }
        cout << steps << endl;
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
    return 0;
}