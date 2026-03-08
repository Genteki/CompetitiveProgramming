#include <bits/stdc++.h>
using namespace std;
// KMP
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int m = t.size();
    t.push_back(' ');
    t.insert(t.end(), s.begin(), s.end());
    int n = t.size();
    vector<int> pi(n + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = pi[i];
        while (k != 0 && t[i + 1] != t[k]) {
            k = pi[k - 1];
        }
        if (t[i + 1] == t[k])
            pi[i + 1] = k + 1;
        else
            pi[i + 1] = k;
        if (pi[i + 1] == m) ans++;
    }
    cout << ans << endl;
    return 0;
}