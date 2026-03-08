// a.cpp

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
#include <queue>

using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int m,n;
	cin >> n >> m;
	vector<int> a(m);

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a.back() == n || a[0] == 1) {
		cout << "-1\n";
		return;
	}
	vector<int> st, ed;
	st.push_back(a[0]);
	for (int i = 0; i < m - 1; ++i) {
		if(a[i] + 1 == a[i+1]) {
			continue;
		} else {
			ed.push_back(a[i]);
			st.push_back(a[i+1]);
		}
	}
	ed.push_back(a[m-1]);
	std::vector<int> ans;
	// for (auto sti : st) cout << sti << " "; cout << endl;
	// for (auto sti : ed) cout << sti << " "; cout << endl;

	int p = 1;
	for (int i = 0; i < st.size(); ++i) {
		while(p < st[i]) {
			ans.push_back(p);
			++p;
		}
		++p;
		while(p <= ed[i] + 1) {
			ans.push_back(p);
			++p;
		}
		ans.push_back(st[i]);
	}

	for (auto ansi : ans) {
		cout << ansi << " ";
	}
	for (;p<=n; ++p) {
		cout << p << " ";
	}
	cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}