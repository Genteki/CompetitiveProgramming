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
const i64 module = 1000000007;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int n, k;
	cin >> n >> k;
	vector<i64> a(n);
	i64 s = 0;
	for (auto &ai : a) {cin >> ai; s+=ai;}
	s = s % module + (s < 0) * module * (i64(-s + module - 1) / module);
	i64 max_curr = 0, max_global = 0;
	pair<int,int> max_pos({0,0}), curr_pos({0,0});
	for(int i = 0; i < n; ++i) {
		max_curr = max(max_curr + a[i], a[i]);
		if (max_curr+a[i] > a[i]) {
			curr_pos.second = i+1;
		} else {
			curr_pos = {i, i + 1};
		}
		if (max_curr >= max_global) {
			max_global = max_curr;
			max_pos = curr_pos;
		}
	}
	for (int i = 0; i < k; ++i) {
		s = s+ max_global;
		max_global *= 2;
		max_global = max_global % module;
	}
	cout << s % module << endl;
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