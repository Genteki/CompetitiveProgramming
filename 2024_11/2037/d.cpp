// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    map<int, vector<int>> mp;
    while(n--) {
        int x, y;
        cin >> x >> y;
        mp[x] = vector<int>{1, y-x+2};
    }
    while(m--) {
        int x, v;
        cin >> x >> v;
        if (mp.find(x) == mp.end()) mp[x] = vector<int>{2, v};
        else mp[x].push_back(v);
    }
    priority_queue<int, vector<int>, std::less<>> pq;
    int power = 1;
    int ans = 0;
    for (auto [x, p] : mp) {
        int inst = p[0];
        if (inst == 1) {
            int val = p[1];
            while (power < val && !pq.empty()) {
                power += pq.top();
                pq.pop();
                ans++;
            }
            if (power < val) {
                cout << -1 << endl;
                return;
            }
        } else {
            for (int i = 1; i < p.size(); ++i)
                pq.push(p[i]);
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}