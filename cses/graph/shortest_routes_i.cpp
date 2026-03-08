// dijastra
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#define debug(f) try { f(); } \
    catch (const std::exception &e) { std::cerr << "Exception: " << e.what() << std::endl; }\
    catch (...) { std::cerr << "Unknown exception occurred" << std::endl;}

using namespace std;

typedef long long i64;
using pli = pair<long, int>;

void solve() {
    int m, n;
    cin >> n >> m;
    vector<vector<pair<int, i64>>> g(n);;
    for (;m--;) {
        int x,y;
        i64 z;
        cin >> x >> y >> z;
        --x; --y;
        g[x].push_back({y,z});
    }
    vector<i64> d(n, LONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    d[0] = 0;
    pq.push({0L, 0});
    while(!pq.empty()) {
        auto [dv, v] = pq.top();
        pq.pop();
        if (dv > d[v]) continue;
        for (auto [to, l] : g[v]) {
            // cout << to << endl;
            if (d[to] > dv + l) {
                d[to] = dv + l;
                pq.push({d[to], to});
            }
        }
    }
    for (i64 di : d) cout << di << " ";
    cout << endl;
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

// void solve() {
//     int m, n;
//     cin >> n >> m;
//     vector<vector<pair<int, i64>>> g(n);;
//     for (;m--;) {
//         int x,y;
//         i64 z;
//         cin >> x >> y >> z;
//         --x; --y;
//         g[x].push_back({y,z});
//     }
//     vector<i64> d(n, LONG_MAX);
//     d[0] = 0;
//     vector<bool> viewed(n, false);
//     vector<int> p(n, -1);
//     for (int i = 0; i < n; ++i) {
//         int v = -1;
//         for (int j = 0; j < n; ++j) {
//             if (viewed[j]==false && (v==-1 || d[j] < d[v])) {
//                 v = j;
//                 // cout << viewed[j];
//             }
//         }
//         if (d[v] == LONG_MAX) {
//             break;
//         }
//         // cout << v << viewed[v] << endl;
//         viewed[v] = true;
//         for (auto & [to, l] : g[v]) {
//             if (d[v] + l < d[to]) {
//                 d[to] = d[v] + l;
//                 p[to] = v;
//             }
//         }
//     }
//     for (auto di : d) cout << di << " "; cout << endl;
//     return;
// }