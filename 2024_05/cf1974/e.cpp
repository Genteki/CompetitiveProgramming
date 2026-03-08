// e.cpp
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

const i64 inf = 0x3f3f3f3f3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int m; i64 x;
	cin >> m >> x;
	const int s = 1000 * m;
	vector<i64> dp(s+1,inf);
	dp[0] = 0;

	vector<int> c(m), h(m);
	for (int i =0; i < m; ++i) {
		int c, h;
		cin >> c >> h;
		// cout << " " << c << " " << h << ":\n";
			i64 money = i * x - c;
			for(i64 j = 1000 * (i+1) - 1; j >= h ; --j) {
				// cout << " " << j;
				if (dp[j - h] <= money) {
					// cout << " " << j;
					dp[j] = min(dp[j], dp[j - h] + c);
				}

		}
	}
	i64 ans = 0;
	for (int i = 0; i < s; ++i) {
		if (dp[i] != inf) {
			ans = i; 
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