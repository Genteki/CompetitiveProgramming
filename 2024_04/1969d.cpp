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


bool compare(const pair<i64, i64>&i, const pair<i64, i64>&j) 
{ 
    return i.second < j.second; 
} 


void solve() {
	int n,k;
	cin >> n >> k;
	std::vector<i64> a(n), b(n);
	for(auto & ai : a) cin >> ai;
	for(auto & bi : b) cin >> bi;	
	i64 profit = 0;
	i64 cost = 0;
	vector<pair<i64,i64>> alist;
	for (int i=0; i < n; ++i) {
		if (a[i] <= b[i]) {
			alist.push_back({a[i],b[i]});
		}
	}
	std::sort(alist.begin(), alist.end(), compare);
	if (k >= alist.size()) {
		cout << 0 << endl;
		return;
	}
	i64 curr_profit = 0;
	for (int i = 0; i < k; ++i) {
		curr_profit -= a[i]; 
	}
	for (int i = k; i < alist.size(); ++i) {
		curr_profit = curr_profit + alist[i-k].second - alist[i].first;
		if (curr_profit > profit) profit = curr_profit;
	}
	bool decreasing = 1;

	i64 m = 0;
	cout << max(profit, m) << endl;
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