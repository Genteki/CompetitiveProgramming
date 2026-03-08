// 1972c.cpp


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
	int n; 
	i64 k;
	cin >> n >> k;
	std::vector<i64> a(n);
	for (auto& ai : a) cin >> ai;

	i64 low = 0, high = (i64)2e12 + 1;
	bool flag = true;
	// cout << "go " << endl;
	while (high - low > 1) {
		i64 mid = (low + high) / 2;
		i64 s = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < mid) {
				s += (0 - a[i] + mid);
			}
		}
		if (s > k) high = mid;
		else low = mid;
	}
	i64 ans = 0;
	if (n == 1) {
		ans = low;
	} else {
		for (int i = 0; i < n; ++i) {
			if (a[i] < low) k -= (low - a[i]);
		}
		ans = (low - 1) * n + 1;
		for (int i = 0; i < n; ++i) {
			if (a[i] > low) {
				ans += 1;
			} else {
				if (a[i] <= low && k > 0) {
					k--;
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