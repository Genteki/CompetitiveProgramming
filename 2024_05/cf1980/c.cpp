#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    input(a);
    input(b);
    int m;
    cin >> m;
    vector<int> c(m, -1), d(m);
    input(d);

    set<int> suf;
    map<int, int> nec;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            suf.insert(a[i]);
        } else {
            nec[b[i]]++;
        }
    }
    if ( (suf.find(d.back()) == suf.end()) && (nec.find(d.back()) == nec.end()) ) {
        cout << "NO" << endl;
        return;
    }

    for (int di : d) {
        if (nec.find(di) != nec.end()) {
            nec[di]--;
            if (nec[di]==0) {
                nec.erase(di);
            }
        }
    }
    if (nec.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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