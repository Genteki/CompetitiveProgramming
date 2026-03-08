// f.cpp

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
    vector<i64> a(n);
    input(a);
    vector<i64> deg(n, 1);
    i64 ans = accumulate(all(a), (i64)0);
    priority_queue< pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>> > pq;
    for (int i = 0; i < n; ++i) {
        pq.push({a[i]*3, i});
    }
    for (int i = 0; i < n-2; ++i) {
        auto tmp = pq.top();
        pq.pop();
        deg[tmp.second]++;
        ans += tmp.first;
        pq.push({a[tmp.second] * (deg[tmp.second] * 2 + 1LL), tmp.second});
    }
    // for (auto degi : deg) cout << degi << " "; 

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