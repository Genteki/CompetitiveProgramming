// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(3, 0);

    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        if (x == 'T') a[i] = 0;
        else if (x == 'I') a[i] = 1;
        else a[i] = 2;
        cnt[a[i]]++;
    }
    
    if (bool(cnt[0]) + bool(cnt[1]) + bool(cnt[2]) <= 1) {
        cout << -1 << endl;
        return;
    }
    if (cnt[0] == cnt[1] and cnt[0] == cnt[2]) {
        cout << 0 << endl;
        return;
    }
    int m = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int q = min_element(cnt.begin(), cnt.end()) - cnt.begin();
    int p = 3 - m - q;
    auto check = [&a, &n](int x, int y, int z, vector<int> cnt) -> bool {
        debug(x,y,z);
        int d = min(cnt[x], cnt[y]) - cnt[z];
        if (cnt[x] < cnt[y]) return false; 
        if (d<0) return false;
        vector<int> cnt2(n, 0);
        vector<int> ans;
        for (int i = 0; i < n-1; ++i) {
            cnt2[i+1] = cnt2[i];
            if (d==0) continue;
            if ((a[i]==x and a[i+1]==y) or (a[i]==y and a[i+1]==x)) {
                ans.push_back(i+1+cnt2[i]);
                cnt2[i+1]++;
                d--;
            } else if (a[i] == z and a[i+1] == y) {
                debug(i);
                ans.push_back(i + 1 + cnt2[i]);
                ans.push_back(i + 2 + cnt2[i]);
                cnt2[i+1]+=2;
                d--;
                cnt[x]++;
            } else if (a[i+1] == z and a[i] == y) {
                ans.push_back(i + 1 + cnt2[i]);
                ans.push_back(i + 1 + cnt2[i]);
                cnt2[i + 1] += 2;
                d--;
                cnt[x]++;
            }
        }
        debug(ans,d);
        if (d > 0) {
            return false;
        }

        int tgt;
        debug(cnt);
        for (int i = 0; i < n-1; ++i) {
            if (a[i] == x and a[i+1] != x) {
                tgt = i + cnt2[i] + 1;
                for (int i = 0; i < 2*(cnt[x]-cnt[y]); ++i) {
                    ans.push_back(tgt);
                }
                break;
            } else if (a[i] != x and a[i+1] == x) {
                tgt = i + cnt2[i] + 1 + (cnt2[i+1]>cnt2[i]);
                for (int i = 0; i < 2 * (cnt[x] - cnt[y]); ++i) {
                    ans.push_back(tgt+i);
                }
                break;
            }
        }
        debug(ans);
        if (ans.size()>2*n) return false;
        cout << ans.size() << endl;
        for (auto ai : ans) cout << ai << endl;
        return true;
    };
    if(!check(m,p,q,cnt))
        if(!check(m,q,p,cnt))
            if(!check(p,m,q,cnt))
                cout << -1 << endl;
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