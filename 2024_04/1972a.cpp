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
	cin >> n;
	vector<int> a(n), b(n), c(n, -1);
	for (int &ai : a) {cin >> ai;};
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		while (b[i] >= a[idx] && idx < n) {
			c[idx] = i;
			idx++;
		}
	}
	int gap = n  - idx;
	for (int i = 0; i < n; ++i) {
		if (c[i] != -1) {
			gap = max(c[i] - i, gap);
		}
	}
	cout << gap << endl;
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