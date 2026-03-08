// https://cses.fi/problemset/task/2129
// Min-cost Max-flow

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
typedef long long i64;
struct Edge{
    int from, to, capacity, cost;
};
vector<vector<int>> adj, cost, capacity;

void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p) {
    d.assign(n, inf);
    d[v0] = 0;
    queue<int> q;
    vector<bool> inq(n, false);
    q.push(0);
    inq[0] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for ()
    }
}

void solve() {
    
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