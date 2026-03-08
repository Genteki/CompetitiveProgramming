#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    bool found_duplicate = false;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            char new_char = (s[i] == 'z') ? 'a' : (s[i] + 1);
            s.insert(s.begin() + i, new_char);
            cout << s << endl;
            found_duplicate = true;
            break;
        }
    }

    if (!found_duplicate) {
        char new_char = (s[n - 1] == 'z') ? 'a' : (s[n - 1] + 1);
        s.push_back(new_char);
        cout << s << endl;
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