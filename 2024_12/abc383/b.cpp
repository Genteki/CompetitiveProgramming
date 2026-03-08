// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector a(n, std::vector<char>(m));
    for (auto & ai : a) for (auto &aii : ai) std::cin >> aii;
    int ans = -1;
    std::vector b(n, std::vector<bool>(m, false));
    auto fill = [](std::vector<std::vector<bool>>& v) -> void {
        for (auto & vi : v) {
            std::fill(vi.begin(), vi.end(), false);
        }
    };

    for (int ix = 0; ix < n; ++ix) {
        for (int iy = 0; iy < m; ++iy) {
            if (a[ix][iy] == '.') {
                fill(b);

                int cur_ans1 = 0, cur_ans2 = 0;
                for (int jx = 0; jx < n; ++jx) {
                    for (int jy = 0; jy < m; ++jy) {
                        if (a[jx][jy] == '.' && b[jx][jy] == false && abs(jx-ix) + abs(jy-iy) <= d) {
                            ++cur_ans1;
                            b[jx][jy] = true;
                        }
                    }
                }
                for (int kx = ix; kx < n; ++kx) {
                    for (int ky = 0; ky < m; ++ky) {
                        if (kx * m + ky > ix * m + iy && a[kx][ky] == '.') {
                            int cur = 0;
                            for (int jx = 0; jx < n; ++jx) {
                                for (int jy = 0; jy < m; ++jy) {
                                    if (a[jx][jy] == '.' &&
                                        b[jx][jy] == false &&
                                        abs(jx - kx) + abs(jy - ky) <= d) {
                                        ++cur;
                                    }
                                }
                            }
                            cur_ans2 = std::max(cur_ans2, cur);
                            debug(cur, kx, ky);
                        }
                    }
                }
                debug(ix, iy, cur_ans1, cur_ans2);
                ans =std::max(cur_ans1+cur_ans2, ans);
            }
        }
    }   
    std::cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}