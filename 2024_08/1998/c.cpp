// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, k;
    cin >> n >> k;
    i64 k2 = k;
    vector<pair<i64, i64>> a(n);
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    bool none = true;
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i].second;
        if (a[i].second) {
            none = false;
        }
    }


    sort(all(a));
    auto b = a;

    i64 m = (n) / 2 - 1;
    i64 med_val = a[m].first;
    if (none == true) {
        i64 ans = a[m].first + a.back().first;
        cout << ans << endl;
        return;
    }

    i64 ans1 = 0;
    i64 p = 0;
    for (i64 i = n - 1; i >= 0; --i) {
        if (a[i].second == 1) {
            p = i;
            break;
        }
    }
    a[p].first += k;
    sort(all(a));
    ans1 = a.back().first + a[m].first;

    i64 tgt_val, tgt_i = -1;

    a = b;
    i64 ans3 = 0;
    tgt_val, tgt_i = -1;
    if (a[m].second == 1) {
        tgt_val = a[m].first;
        tgt_i = m;
    } else {
        for (i64 i = m - 1; i >= 0; --i) {
            if (a[i].second == 1) {
                tgt_val = a[i].first;
                tgt_i = i;
                break;
            }
        }
    }
    k = k2;
    i64 remain = 0;
    if (tgt_i == -1) {
        ans3 = -1;
    } else {
        i64 cul = 1;
        i64 nxt = tgt_i + 1;
        i64 prev = tgt_i - 1;
        i64 s = a[tgt_i].first;
        while(prev >= 0 && a[prev].second == 0) {
            --prev;
        }
        while (k > 0 && nxt < n-1) {
            if (a[nxt].second == 0) {
                if (prev >= 0) {
                    if (s + a[prev].first + k >= a[nxt].first * (cul+1)) {
                        nxt++;
                        ++cul;
                        s += a[prev].first;

                        --prev;
                        while (prev >= 0 && a[prev].second == 0) {
                            --prev;
                        }
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                if (s + k > cul * a[nxt].first) {
                    s += a[nxt].first;

                    cul++;
                    nxt++;
                } else {
                    break;
                }
            }
        }
        if (k > 0) {
            tgt_val = (s + k) / cul;
            remain = (s + k) % cul;
        }
        // cout << s << ", " << cul << " :";

        // for (auto ai : a) cout << ai.first << " "; cout << endl;

        for(i64 i = prev+1; i < nxt; ++i) {
            if (a[i].second) {
                a[i].first = max(tgt_val, a[i].first);
                if (remain) {
                    a[i].first++;
                    --remain;
                }
            }
        }
    // for (auto ai : a) cout << ai.first << " "; cout << endl;

        sort(all(a));
        ans3 = a.back().first + a[m].first;
    }


    cout << max({ans1, ans3}) << endl;
    // cout << max({ans1, ans3}) << " " << ans3 << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}