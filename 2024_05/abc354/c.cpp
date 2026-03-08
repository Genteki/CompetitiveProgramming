// c.cpp

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
	map<int,int> ac_map, ca_map;
	vector<int> an(n);
	for (int i = 0; i < n; ++i) {
		int a,c;
		cin >> a >> c;
		ac_map[a] = c;
		ca_map[c] = a;
		an[i] = a;
	}
	set<int> remove_item;
	int min_cost = (int)1e9+1;
	for (auto aci = ac_map.rbegin(); aci != ac_map.rend(); ++aci) {
		// cout << aci->second << " " << min_cost << endl;
		if (aci->second < min_cost) {
			min_cost = aci->second;
		} else {
			remove_item.insert(aci->first);
			// cout << aci -> first << " " << aci -> second << endl;
		}
	}
	
	// int min_stren = (int)1e9+1;
	// for (auto cai = ca_map.rbegin(); cai != ca_map.rend(); ++cai) {
	// 	cout << (cai->second) << " " << min_stren << endl;
	// 	if (cai->second < min_stren) {
	// 		min_stren = cai->second;
	// 	} else {
	// 		remove_item.insert(cai->second);
	// 		cout << cai -> first << " " << cai -> second << endl;

	// 	}
	// }
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (remove_item.find(an[i]) == remove_item.end()) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	// for (auto ri : remove_item) {
	// 	cout << ri << " ";
	// }cout << endl;
	for (auto ansi : ans) {
		cout << (ansi+1) << " ";
	}
	cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}