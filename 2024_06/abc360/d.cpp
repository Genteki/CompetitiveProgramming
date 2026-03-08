// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    i64 t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<i64> x(n);
    vector<i64> left, right;
    input(x);


    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            left.push_back(x[i]);
        } else {
            right.push_back(x[i]);
        }
    }
    if (left.empty() || right.empty()) {
        cout << 0  << endl;;
        return;
    }

    sort(all(left));
    sort(all(right));

    size_t li = 0;
    vector<size_t> start(right.size(), left.size()),
        end(right.size(), left.size());
    for (size_t ri = 0; ri < right.size(); ++ri) {
        while (li < left.size() && right[ri] > left[li]) {
            ++li;
        }
        start[ri] = li;
    }
    li = 0;
    for (size_t ri = 0; ri < right.size(); ++ri) {
        while (li < left.size() && (right[ri] + 2 * t) >= left[li]) {
            ++li;
        }
        end[ri] = li;
    }
    i64 ans = 0;
    for (size_t i = 0; i < start.size(); ++i) {
        ans = ans + end[i] - start[i];
    }
    cout << ans << endl;
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