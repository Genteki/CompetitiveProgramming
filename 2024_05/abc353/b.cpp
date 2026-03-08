// b.cpp
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int j = 0, t = k;
	for (int i = 0; i < n; ++i) {
		int g; cin >> g;
		if (t == k) {
			t -= g;
			j++;
		} else if (t >= g) {
			t -= g;
		} else {
			// t = k;
			j++;
			t = k - g;
		}
	}
	cout << j << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}