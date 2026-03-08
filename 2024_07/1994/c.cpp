// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n,x;
    cin >> n >> x;
    vector<i64> a(n);
    input(a);
    vector<i64> ps(n+1, 0);
    for (int i = 0; i < n; ++i) {
        ps[i+1] = ps[i] + a[i];
    }
    auto search = [&](int l) -> int {
        int low = l, high = n;
        if (ps[high] - ps[low] <= x) {
            return -1;
        }
        while(high - low > 1) {
            int mid = (high + low) / 2;
            if (ps[mid] - ps[l] > x) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    };
    vector<vector<int>> adj(n+1);


    vector<bool> viewed(n+1, false);
    for (int i = 0; i < n; ++i) {
        if (viewed[i]) continue;
        int cur = i, nxt;
        while(cur != -1 && (!viewed[cur])) {
            viewed[cur] = true;
            nxt = search(cur);
            if(nxt!=-1) adj[cur].push_back(nxt);
            cur = nxt;
        }
    }

    // for (auto adji : adj) {
    //     for (auto adjii : adji) {
    //         cout << " " << adjii;
    //     }
    //     cout << endl;
    // }

    vector<i64> tails(n+1, 0);
    fill(all(viewed), false);
    i64 ans = n * (n+1) / 2;
    for (int i = n-1; i >= 0; --i) {
        if (adj[i].size() == 0) {
            continue;
        }
        tails[i] = adj[i].size() + tails[adj[i].back()];
    }
    for (auto ti : tails) {
        ans -= ti;
    }
    cout << ans << endl;
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