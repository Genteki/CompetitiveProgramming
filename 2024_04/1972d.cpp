// 1972d.cpp

// #include <bits/stdc++.h>
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
#include <regex>

using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int m,n;
	cin >> m >> n;
	int max_gcd = min(m, n);
	int ans = 0;
	for (int gcdx = 1; gcdx <= min(m,n); ++gcdx) {
		int max_ka = m / gcdx;
		int max_kb = n / gcdx;
		for (int kb = 1; kb <= min(max_ka, max_kb); ++kb) {
			int max_p = (max_ka / kb + 1) / gcdx;
			int min_p = max(1, (1 / kb + 1) / gcdx);
			for (int p = min_p; p <= max_p; ++p) {
				int ka = (p*gcdx-1)*kb;
				if (gcd(ka, kb) == 1) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
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
}