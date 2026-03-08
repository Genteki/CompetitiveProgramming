#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x] += 1;
    }
    vector<int> b(mp.size(), 0);
    int ib = 0;
    for (auto& [vi, ni] : mp) {
        b[ib] = ni;
        ++ib;
    }

    priority_queue<int> pq;
    int bal = 1;
    int r = 0;
    for (int i = 1; i < b.size(); ++i) {
        pq.push(b[i]);
        bal -= b[i];
        if (bal < 0) {
            bal += pq.top();
            pq.pop();
        } else {
            ++r;

            bal--;
        }
        bal++;
    }
    cout << (b.size()-r) << endl;
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