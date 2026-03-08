// d.cpp

#include <bits/stdc++.h>
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
	int n ;
	cin >> n;
	vector<pair<int, int>> v(n);
	i64 ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;

	for (auto & vi : v) {
		cin >> vi.first >> vi.second;
	}
	
	sort(v.begin(), v.end(), [](auto& x, auto&y ){return x.first < y.first;});

	for (auto & vi : v) {
		while(!q.empty() && q.top() < vi.first) {
			q.pop();
		}
		// int l = q.size();
		ans += q.size();
		q.push(vi.second);
	}
	cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}