#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    // reverse(all(s));
    vector<pair<char,int>> a;
    a.push_back({s[0], 1});
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            a.back().second++;
        } else {
            a.push_back({s[i], 1});
        }
    }
    // if (a.size()==1) {
    //     if (a[0].second <= k) {
    //         cout << n << endl;
    //     } else {
    //         cout << -1 << endl;
    //     }
    //     return;
    // }
    
    int break_point = -1;
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].second > k) {
            break_point = i;
            a[i].second -= k;
            ans = a[i].second;
            if (a.back().first == a[i].first && a[i].second+a.back().second==k) {
                a.back().second = k;
                a[i].second = k;
                break;
            } else if (a.back().first != a[i].first && a[i].second == k && a.back().second==k) {
                a.back().second = k;
                a[i].second = k;
                break;
            } else {
                cout << -1 << endl;

                return;
            }
        }
    }

    if (break_point == -1) {
        for (int i = 1; i < a.size()-1;++i) {
            if(a[i].second < k) {
                break_point = i;
                ans = a[i].second;
                if (a.back().first == a[i].first &&
                    a[i].second + a.back().second == k) {
                    a.back().second = k;
                    a[i].second = k;
                    break;
                } else {
                    cout <<-1 << endl;
                    return;
                }
            }
        }
    }

    if (break_point == -1 && a.back().first == a[0].first && (a.back().second+a[0].second)==k ) {
        break_point = 0;
        ans = a[0].second;
        a.back().second = k;
    }

    for (int i = 1; i < a.size(); ++i) {
        if (a[i].second != k) {
            cout << -1 << endl;
            return;
        }
    }

    if (break_point == -1) {
        cout << n << endl;
    } else {
        for (int i = 0; i < break_point; ++i) {
            ans += (a[i].second);
        }
        cout << ans << endl;
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