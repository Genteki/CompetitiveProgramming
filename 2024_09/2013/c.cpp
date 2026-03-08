// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    flush;
    int n;
    cin >> n;
    string query;
    int cnt = 0;
    query = "1";
    cout << "? " << query << endl; flush;
    cnt++;

    bool recv;
    cin >> recv;
    if (!recv) {
        cout << "! " << string(n, '0') << endl;
        flush;
        return;
    }
    bool flag = true;
    while (flag && query.size() < n) {
        query += "1";
        cout << "? " << query << endl; flush;
        cnt++;

        cin >> recv;
        if (recv) {
            continue;
        } else {
            query.back() = '0';
            cout << "? " << query << endl; flush;
            cnt++;

            cin >> recv;
            if (!recv) {
                query.pop_back();
                break;
            }
        }
    }
    if (query.size() == n) {
        cout << "! " << query << endl;
        flush;
        return;
    }
    int z = query.size();
    for (int i = 0; i < n-z; ++i) {
        cout << "? " << "1" << query << endl; flush;
        cnt++;

        cin >> recv;
        if (recv) query = "1" + query;
        else query = "0" + query;
    }
    cout << "! " << query << endl;
    // debug(cnt);
    // cout << cnt << endl;
    flush;

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
