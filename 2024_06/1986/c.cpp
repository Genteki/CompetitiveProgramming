#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s; // len n
    vector<int> ind(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        ind[i] = x;
    }
    string c;
    cin >> c; // len m

    vector<char> d(n, '*');
    sort(all(ind));
    sort(all(c));

    int j = 0;

    for (int i = 0; i < m; ++i) {
        if (i > 0 && ind[i] == ind[i-1]) continue;
        d[ind[i]] = c[j];
        j++;
    }

    for (int i = 0; i < n; ++i) {
        s[i] = (d[i] == '*' ? s[i] : d[i]);
    }
    cout << s << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}