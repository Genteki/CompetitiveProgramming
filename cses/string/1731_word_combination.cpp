#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto &ai : (x)) std::cin >> ai
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    vector trie(1e6+5, vector<int>(26,-1));
    vector ed(1e6+5, 0);
    int cursor = 1;
    for (int i = 0; i < k; ++i) {
        string t;
        cin >> t;
        int node = 0;
        for (auto &ti : t) {
            if (trie[node][ti - 'a'] == -1) {
                trie[node][ti - 'a'] = cursor;
                node = cursor++;
            } else {
                node = trie[node][ti - 'a'];
            }
        }
        ed[node] = t.size();
    }
    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int node = 0;
        if (dp[i] == 0) continue;
        for (int j = i; j < n; ++j) {
            if (trie[node][s[j] - 'a'] == -1) {
                break;
            }
            node = trie[node][s[j] - 'a'];
            if (ed[node]) {
                dp[j + 1] += dp[i];
                dp[j + 1] %= MOD;
            }
        }
    }
    cout << dp[n];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}