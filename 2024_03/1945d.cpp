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
	int n, m;
	cin >> n >> m;
	vector<i64> a(n), b(n);
	for (auto & ai : a) cin >> ai;
	for (auto & bi : b) cin >> bi;
	vector<i64> c(n+1, 0);
	for (int i = 0; i < n; ++i) {
		c[n-1-i] = c[n-i] + min(a[n-1-i], b[n-1-i]);
	} 
	vector<i64> d(n);
	for (int i = 0; i < n; ++i) {
		d[i] = c[i+1] + a[i];
		// cout << d[i] << " ";
	}
	cout << *min_element(d.begin(), d.begin() + m) << endl;
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