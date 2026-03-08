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
	map<i64, int> mp;
	i64 x;	
	for(int i = 0; i < n; ++i) {
		cin >> x;
		mp[x] += 1;
	}
	int mid = (n+1) / 2;
	int count = 0;
	for (auto & p : mp) {
		count += p.second;
		// cout << p.first << " ";
		if (count >= mid) {
			cout << count - (n-1)/2 << endl;
			break;
		}
	}
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