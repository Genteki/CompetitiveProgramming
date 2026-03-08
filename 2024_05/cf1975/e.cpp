#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef long long i64;
 
const int inf = 0x3f3f3f3f;

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T> &v) {
    for (auto & vi : v) os << vi << " ";
    // os << endl;
    return os;
}
    
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> color(n, 0);
    vector<vector<int>> g(n);
    vector<unordered_set<int>> g_black(n);
    int s = 0;
    for (auto& ci : color) cin >> ci;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    vector<int> bn(4, 0);

    vector<int> black_neighbor(n, 0);
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) {
            s += 1;
            for (int gi : g[i]) {
                if (color[gi] == 1) g_black[i].insert(gi);
            }
            if (g_black[i].size() >= 3) bn[3]++; 
            else bn[g_black[i].size()] ++;
        }
    }

    for (int i = 0; i < q; ++i) {
        int v;
        cin >> v; v--;
        color[v] = color[v] == 1 ? 0 : 1;
        
        if (color[v]==1) {
            for(int gvi : g[v]) {
                if (color[gvi] == 1) {
                    g_black[gvi].insert(v);
                    g_black[v].insert(gvi);
                    int ns = g_black[gvi].size();
                    if(ns <= 3) {bn[ns]++; bn[ns-1]--;}
                }
            }
            if (g_black[v].size() >= 3) bn[3] ++;
            else bn[g_black[v].size()]++;
            s++;
        } else {
            for(int gvi : g_black[v]) {
                g_black[gvi].erase(v);
                int ns = g_black[gvi].size();
                if (ns < 3) {bn[ns] ++; bn[ns+1]--;}
            }
            if (g_black[v].size() >= 3) bn[3]--;
            else bn[g_black[v].size()]--;
            g_black[v].clear();
            s--;
        }

        
        bool ans = false;
        if (s==1) {
            ans = true;
        } else if (s > 0 && bn[1] == 2 && bn[3] == 0 && bn[0] == 0) {
            ans = true;
        }
        // cout << bn << endl;
        if (ans) cout << "yes\n";
        else cout << "no\n";
    }
    return;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int test_cases;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
    return 0;
}
