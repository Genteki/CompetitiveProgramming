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
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto & ai : a) cin >> ai;
	for (auto & bi : b) cin >> bi;

	if (n <= 1) {
		cout << "No\n";
		return;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0;
	int j = 0;
	int steak = 0;
	while(j < m) {
		steak = 0;
		while (i < n && a[i] < b[j]) {
			steak++;
			i++;
			if (steak >= 2) {
				// cout << i << endl;
				cout << "Yes\n";
				return;
			}
		}
		++j;
	}
	if (i < n-1) cout << "Yes\n";
	else cout << "No\n";
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}