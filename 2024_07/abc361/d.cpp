// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n; cin >> n;
    int N = (1 << (n+1)) * (n+1);
    int l = 1 << (n+1);
    vector<bool> viewed(N, false);
    vector<char> s(n+2, '.');
    vector<char> t(n+2, '.');
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];
    int ws=0, wt=0;
    for (int i = 0; i < n; ++i) {
        ws = ws + (s[i] == 'W');
        wt = wt + (t[i] == 'W');
    }
    if (ws != wt) {
        cout << -1;
        return;
    }
    auto encode = [&n, &l](vector<char>& x) -> int {
        int ppos = 0;
        for (int i = 0; i < n+2; ++i) {
            if (x[i] == '.') {
                ppos = i;
                break;
            }
        }
        int j = 0;
        int r = 0;
        for (char & xi : x) {
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
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int pc = encode(p);
        if (pc == tc) { viewed[pc] = true; break;}
        // if (viewed[pc]) continue;
        viewed[pc] = true; 

        int ppos = 0;
        for (int i = 0; i < n + 1; ++i) {
            if (p[i] == '.') {
                ppos = i;
                break;
            }
        }
        for (int i = 0; i < n + 1; ++i) {
            if (p[i] == '.' || p[i + 1] == '.') {
                continue;
            }
            auto to = p;
            swap(to[i], to[ppos]);
            swap(to[i + 1], to[ppos + 1]);
            // for (auto toi : to) cout << toi; cout << endl;
            int toc = encode(to);
            if (!viewed[toc]) {
                q.push(to);
                parent[toc] = pc;
                // cout << q.size() << endl;
                viewed[toc] = true;  // Mark it as viewed
            }
        }
    }
    if (viewed[tc] == false ) {
        cout << -1;
    } else {
        int ans = 0;
        while(tc != sc) {
            tc = parent[tc];
            ans++;
        }
        cout << ans;
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