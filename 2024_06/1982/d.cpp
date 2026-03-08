#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<i64>> h(n, vector<i64>(m));
    for (auto & hi : h) {
        for (auto & hii : hi) {
            cin >> hii;
        }
    }
    vector<vector<int>> snow(n, vector<int>(m, 0));
    for (auto& si : snow) {
        for (auto & sii : si) {
            char x;
            cin >> x;
            if (x == '1') {
                sii = 1;
            } else {
                sii = -1;
            }
        }
    }

    i64 s0 = 0, s1 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (snow[i][j] == 1) {
                s1 += h[i][j];
            } else {
                s0 += h[i][j];
            }
        }
    }

    set<i64> coins;
    vector<vector<i64>> cnt(n-k+1, vector<i64>(m-k+1, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cnt[0][0] += snow[i][j];
        }
    }
    
    for (int i = 1; i < n + 1 - k; ++i) {
        cnt[i][0] = cnt[i-1][0];
        for (int j = 0; j < k; ++j) {
            cnt[i][0] = cnt[i][0] - snow[i-1][j] + snow[i+k-1][j];
        }
    }

    for (int j = 1; j < m + 1 - k; ++j) {
        for (int i = 0; i < n + 1 - k; ++i) {
            cnt[i][j] = cnt[i][j-1];
            for (int q = 0; q < k; ++q) {
                cnt[i][j] = cnt[i][j] - snow[i+q][j-1] + snow[i+q][j+k-1];
            }
        }
    }

    // for (auto &ci : cnt) {
    //     for (auto& cii : ci) {
    //         cout << cii << " ";
    //     }
    //     cout << endl;
    // }

    for (auto& ci : cnt) {
        for (auto& cii : ci) {
            coins.insert(abs(cii));
        }
    }
    i64 diff = abs(s0 - s1);

    if (coins.find(0LL) != coins.end()) {
        coins.erase(0LL);
    }

    vector<i64> st(all(coins));
    // cout << " " << st.size() << endl;
    if (diff == 0){ 
        cout << "YES" << endl;
    } else if (st.size() == 0) {
        cout << "NO" << endl;
    } else if (st.size() == 1) {
        if (st[0] == 0 || diff % st[0] == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (k % 2 == 1) {
        cout << "YES" << endl;
    } else {
        while(st.size() > 1) {
            coins.clear(); 
            coins.insert(st[0]);
            for (int i = 1; i < st.size(); ++i) {
                if (st[i] % st[0] != 0)
                    coins.insert(st[i] % st[0]);
            }
            st = vector<i64>(all(coins));
        }
        if (diff % st[0] == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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