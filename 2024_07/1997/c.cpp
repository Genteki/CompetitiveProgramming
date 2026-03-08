#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    // s[0] = '(';

    int l = 0, r = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            l--;
        } else if (s[i] == ')') {
            l++;
        }
    }

    l = (n / 2 + l) / 2;
    r = n / 2 - l;


    
    i64 ans = 0 ;
    int curr = 0;
    s[0] = '(';
    l--;
    curr++;

    for (int i = 1; i < n; i += 2) {
        if (s[i] == '(') {
            curr++;
        } else {
            curr--;
        }

        if (curr > 0) {
            if (r) {
                r--;
                s[i+1] = ')';
                curr--;
            } else {
                s[i+1] = '(';
                l--;
                curr++;
            }
        } else {
            curr++;
            s[i+1] = '(';
            l--;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ans -= i;
        } else {
            ans += i;
        }
    }
    // cout << s << endl;
    cout << ans  << endl;
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