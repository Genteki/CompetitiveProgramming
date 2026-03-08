// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.first != b.first) return a.first > b.first;
        else return (a.second > b.second);
    }
};
void solve() {
    int cnt = 0;
    int n;
    cin >> n;
    vector<int> parent(n, -1);
    parent[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int p;
    for (int i = 2; i < n; ++i) {
        cout << "? " << 1 << " " << i << endl;
        ++cnt;
        cout.flush();
        int r;
        cin >> r;
        if (r){ 
            parent[i] = 0;
            pq.emplace(0, i);
        }
        else {
            parent[i] = 1;
            p = i;
            pq.emplace(1, i);
            break;
        }
    }
    for (int i = p + 1; i < n; ++i) {
        while (parent[i] == -1) {
            auto [u, v] = pq.top();
            pq.pop();
            cout << "? " << v << " " << i << endl;
            ++cnt;
            cout.flush();
            int r;
            cin >> r;
            if (!r) {
                parent[i] = v;
                pq.emplace(v, i);
            }
        }
    }
    cout << "! ";
    for (int i = 1; i < n; ++i) {

        cout << parent[i] << " ";
    }
    cout << endl;
    cout.flush();
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